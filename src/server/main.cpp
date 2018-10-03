#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include "QSqlError"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");
    db.setDatabaseName("timetable_planner");
    db.setUserName("timetable_user");
    db.setPassword("timetable_user");

    if(db.open()) {
        qDebug() <<"opened" ;
        db.close();
    } else {
        qDebug() << db.lastError().text();
        exit(1);
    }

    return a.exec();
}
