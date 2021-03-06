#pragma once

#ifndef __LOGIN__H__
#define __LOGIN__H__

#include <string>

#include <QObject>
#include <QString>

namespace chronos {

class Login : public QObject {

    Q_OBJECT

public:

    Login(QObject *parent = nullptr);

signals:

    void logged_in();

public slots:

    bool ok_pressed(
        QString user,
        QString password,
        QString ip,
        QString database
    );

    QString last_error();

private:

};

}

#endif //__LOGIN__H__

