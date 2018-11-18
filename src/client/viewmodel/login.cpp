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

    return DatabaseService::instance().test();
}

