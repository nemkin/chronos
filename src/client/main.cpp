#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "model/manual/database_service.h"
#include "client/viewmodel/login.h"
#include "client/viewmodel/tables.h"

int main(int argc, char *argv[]) {
    
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine(QUrl("qrc:/qml/MainWindow.qml"));

    chronos::Login login;
    chronos::Tables tables;

    engine.rootContext()->setContextProperty("LoginViewModel", &login);
    engine.rootContext()->setContextProperty("TablesViewModel", &tables);

    auto result = app.exec();

    chronos::DatabaseService::destroy();

    return result;
}
