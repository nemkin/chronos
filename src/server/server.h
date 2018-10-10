#pragma once

#ifndef __SERVER__H__
#define __SERVER__H__

#include <QtCore>
#include <QtNetwork>

namespace chronos {

class Server : public QObject {

    Q_OBJECT

public:
    explicit Server(QObject *parent = 0);

signals:
    void data_received(QByteArray data);

private slots:
    void new_connection();
    void disconnected();
    void ready_read();

private:
    QTcpServer* _tcp_server;

    QHash<QTcpSocket*, QByteArray*> buffers;
    QHash<QTcpSocket*, qint32*> sizes;    
};

}

#endif //__SERVER__H__

