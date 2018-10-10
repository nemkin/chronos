#pragma once

#ifndef __CLIENT__H__
#define __CLIENT__H__

#include <QtCore>
#include <QtNetwork>

namespace chronos {

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = 0);

public slots:
    bool connect_to_host(QString host);
    bool write_data(QByteArray data);
    bool read_data();

private:
    QTcpSocket *socket;

};

}

#endif //__CLIENT__H__

