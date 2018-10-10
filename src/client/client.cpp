#include "client.h"

#include <QDebug>

using namespace chronos;

static inline QByteArray IntToArray(qint32 source);

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connect_to_host(QString host)
{
    socket->connectToHost(host, 5005);
    return socket->waitForConnected();
}

bool Client::write_data(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(IntToArray(data.size())); //write size of data
        socket->write(data); //write the data itself
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

bool Client::read_data() {

    connect(socket, &QTcpSocket::readyRead, [=]() {

    while (socket->bytesAvailable() > 0)
       {
           QByteArray buffer = socket->readAll();
           qDebug() << QString::fromStdString(buffer.toStdString());
       }

    });

    return true;

}

QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}
