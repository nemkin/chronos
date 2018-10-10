#pragma once

#ifndef __DEPARTMENT__H__
#define __DEPARTMENT__H__

#include <QObject>
#include <QString>
#include <QJsonObject>

namespace chronos {

class Department {

public:

    Department();
 
    Department(
        int p_id,
        QString p_name,
        int p_timestamp,
        bool p_is_deleted
    );

    QString name() const;
    
    QJsonObject to_json();
    static Department from_json(QJsonObject json);        

private:

    int _id;
    QString _name;
    int _timestamp;
    bool _is_deleted;
    
};

}

#endif //__DEPARTMENT__H__

