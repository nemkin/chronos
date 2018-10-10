#include <QApplication>
#include <QDebug>

#include "server/database/database.h"
#include "server/server.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    chronos::Database db;

    db.test();
    //db.drop();
    //db.init();

    QList<chronos::Department> departments = db.get_departments();

    for(auto d: departments) {
        qDebug() << d.name();
    }

    chronos::Server s;
    
    a.exec();
}
