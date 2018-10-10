#include <QApplication>
#include <QDebug>

#include "client/client.h"

int main(int argc, char *argv[]) {
    
    QApplication a(argc, argv);

    chronos::Client c;
   
    c.connect_to_host("127.0.0.1");
    
    qDebug()<<"Connected.";

    c.write_data(QString("get_all_departments").toUtf8());
    c.read_data();
    c.read_data();
    c.read_data();
    c.read_data();
    c.read_data();

    qDebug()<<"Written.";

    return a.exec();
}
