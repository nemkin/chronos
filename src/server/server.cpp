#include "server.h"

#include <QDebug>

#include "server/service/service.h"

using namespace chronos;

static inline qint32 ArrayToInt(QByteArray source);

Server::Server(QObject *parent) : QObject(parent) {

   _tcp_server = new QTcpServer(this);
   connect(_tcp_server, &QTcpServer::newConnection, this, &Server::new_connection);

   qDebug() << "Listening: " << _tcp_server->listen(QHostAddress::Any, 5005);
}

void Server::new_connection() {

    while(_tcp_server->hasPendingConnections()) {

        QTcpSocket *socket = _tcp_server->nextPendingConnection();
        connect(socket, &QTcpSocket::readyRead, this, &Server::ready_read);
        connect(socket, &QTcpSocket::disconnected, this, &Server::disconnected);

        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);

        buffers.insert(socket, buffer);
        sizes.insert(socket, s);
    }
}

void Server::disconnected() {

   QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
   QByteArray *buffer = buffers.value(socket);
   
   qint32 *s = sizes.value(socket);
   socket -> deleteLater();

   delete buffer;
   delete s;
}

void Server::ready_read() {

   QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
   QByteArray *buffer = buffers.value(socket);

   qint32 *s = sizes.value(socket);
   qint32 size = *s;

   while (socket->bytesAvailable() > 0)
   {
       buffer->append(socket->readAll());
       while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
       {
           if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
           {
               size = ArrayToInt(buffer->mid(0, 4));
               *s = size;
               buffer->remove(0, 4);
           }
           if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
           {
               QByteArray data = buffer->mid(0, size);
               buffer->remove(0, size);
               size = 0;
               *s = size;
               emit data_received(data);
                
               Service service;
               socket->write(service.reply_to(data)); 
                
               qDebug()<<QString(data);
           }
       }
   }
}

qint32 ArrayToInt(QByteArray source) {
   qint32 temp;
   QDataStream data(&source, QIODevice::ReadWrite);
   data >> temp;
   return temp;
}

