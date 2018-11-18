#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/manual/database_service.h"

int main(int argc, char *argv[]) {
    
    QGuiApplication app(argc, argv);

    chronos::DatabaseService::init("nemkin", "nemkin", "10.240.2.125", "chronos");
    
    chronos::DatabaseService::instance().test(); 

    QQmlApplicationEngine engine(QUrl("qrc:/qml/login.qml"));

    auto result = app.exec();

    chronos::DatabaseService::destroy();

    return result;
}
