#include "login.h"

#include "model/manual/database_service.h"

using namespace chronos;

Login::Login(QObject *parent) :
    QObject(parent) {

}

bool Login::ok_pressed(
    QString user,
    QString password,
    QString ip,
    QString database
) {

    DatabaseService::init(
        user.toStdString(),
        password.toStdString(),
        ip.toStdString(),
        database.toStdString()
    );


    if (DatabaseService::is_initialized() && DatabaseService::instance().test()) {
       
        emit logged_in(); 
        return true;

    } else {

        return false;
    }
}

QString Login::last_error() {

    return QString::fromStdString(DatabaseService::last_error());
}

