#include "database.h"

#include <QDebug>
#include <QSqlError>

using namespace chronos;

Database::Database() {

    _db = QSqlDatabase::addDatabase("QPSQL");
    _db.setHostName("localhost");
    _db.setDatabaseName("timetable_planner");
    _db.setUserName("timetable_user");
    _db.setPassword("timetable_user");
}

void Database::test() {

    if(_db.open()) {
        qDebug() <<"Database connection works." ;
        _db.close();

    } else {
        qDebug() << _db.lastError().text();
        exit(1);
    }
}

