TEMPLATE = app
TARGET = client

QT += core qml quick

include(model/model.pri)

HEADERS += \
    client/viewmodel/login.h \
    client/viewmodel/tables.h \


SOURCES += \
    client/main.cpp \
    client/viewmodel/login.cpp \
    client/viewmodel/tables.cpp \


RESOURCES += client/resources.qrc

LIBS += -lpqxx -lpq

client.path = /home/nemkin
INSTALLS += client
