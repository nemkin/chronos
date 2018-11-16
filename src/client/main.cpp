#include <iostream>
#include <string>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/generated/database/database.h"

int main(int argc, char *argv[]) {
    
    QGuiApplication app(argc, argv);

    chronos::Database d("nemkin", "nemkin");
    
    d.test(); 

    QQmlApplicationEngine engine(QUrl("qrc:/qml/main.qml"));

    return app.exec();
}
