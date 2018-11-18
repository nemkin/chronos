#pragma once

#ifndef __LOGIN__H__
#define __LOGIN__H__

#include <string>

#include <QObject>
#include <QString>

class Login : public QObject {

    Q_OBJECT

public:

    Login(QObject *parent = nullptr);

public slots:

    void ok_pressed(
        QString user,
        QString password,
        QString ip,
        QString database
    );

private:

}

#endif //__LOGIN__H__

