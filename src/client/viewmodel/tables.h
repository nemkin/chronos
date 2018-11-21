#pragma once

#ifndef __TABLES__H__
#define __TABLES__H__

#include <memory>
#include <string>

#include <QObject>
#include <QString>
#include <QQmlContext>

#include "client/viewmodel/class_view_model.h"

namespace chronos {

class Tables : public QObject {

    Q_OBJECT

public:

    Tables(
        QQmlContext *p_root_context,
        QObject *parent = nullptr
    );

public slots:

    void logged_in();

private:

    QQmlContext *_root_context;

    std::unique_ptr<chronos::ClassViewModel> _class_view_model;
};

}

#endif //__TABLES__H__

