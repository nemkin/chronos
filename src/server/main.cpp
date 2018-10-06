#include <QApplication>
#include <QDebug>

#include "database/database.h"

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

    return 0; // a.exec();
}
