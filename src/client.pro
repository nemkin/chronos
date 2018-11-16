TEMPLATE = app
TARGET = client

QT += core qml quick

include(model/model.pri)

SOURCES += client/main.cpp

RESOURCES += client/resources.qrc

LIBS += -lpqxx -lpq

client.path = /home/nemkin
INSTALLS += client
