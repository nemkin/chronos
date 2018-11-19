#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "model/manual/database_service.h"
#include "client/viewmodel/login.h"

int main(int argc, char *argv[]) {
    
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine(QUrl("qrc:/qml/MainWindow.qml"));

    chronos::Login login;

    engine.rootContext()->setContextProperty("LoginViewModel", &login);

    auto result = app.exec();

    chronos::DatabaseService::destroy();

    return result;
}
