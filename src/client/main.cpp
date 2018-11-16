#include <iostream>
#include <string>

#include <QCoreApplication>
#include <QtQml/QQmlApplicationEngine>

#include "model/generated/database/database.h"

int main(int argc, char *argv[]) {
    
    QCoreApplication app(argc, argv);

    std::string user;
    std::string pass;

    std::cout<<"User: ";
    std::cin>>user;

    std::cout<<"Pass: ";
    std::cin>>pass;


    chronos::Database d(user, pass);
    
    d.test(); 

    auto list = d.get_departments();
    
    for(auto dep : list) {

        std::cout << dep.to_string();
    }

    QQmlApplicationEngine engine(QUrl("qrc:/main.qml"));

    return app.exec();
}
