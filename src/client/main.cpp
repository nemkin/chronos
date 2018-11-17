#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/generated/database/database.h"

int main(int argc, char *argv[]) {
    
    QGuiApplication app(argc, argv);

    chronos::Database d("nemkin", "nemkin", "10.240.2.125", "chronos");
    
    d.test(); 

    QQmlApplicationEngine engine(QUrl("qrc:/qml/login.qml"));

    return app.exec();
}
