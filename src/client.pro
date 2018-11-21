TEMPLATE = app
TARGET = client

QT += core qml quick

include(model/model.pri)

HEADERS += \
    client/viewmodel/login.h \
    client/viewmodel/tables.h \
    client/viewmodel/class_view_model.h \


SOURCES += \
    client/main.cpp \
    client/viewmodel/login.cpp \
    client/viewmodel/tables.cpp \
    client/viewmodel/class_view_model.cpp \


RESOURCES += client/resources.qrc

LIBS += -lpqxx -lpq

client.path = /home/nemkin
INSTALLS += client
