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

    std::string user() const;
    std::string password() const;
    std::string ip() const;
    std::string database() const;

public slots:

    void ok_pressed(
        QString user,
        QString password,
        QString ip,
        QString database
    );

private:

    void connect();

    std::string _user;
    std::string _password;
    std::string _ip;
    std::string _database;

}

#endif //__LOGIN__H__

