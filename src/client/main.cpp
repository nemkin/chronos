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
    chronos::Tables tables(engine.rootContext());

    QObject::connect(
        &login,
        &chronos::Login::logged_in,
        &tables,
        &chronos::Tables::logged_in
    );

    engine.rootContext()->setContextProperty("login_view_model", &login);
    engine.rootContext()->setContextProperty("tables_view_model", &tables);

    auto result = app.exec();

    chronos::DatabaseService::destroy();

    return result;
}
