#include "service.h"

#include <QList>
#include <QDataStream>

#include "server/database/database.h"
#include "common/entities/department.h"

using namespace chronos;

Service::Service() {

}

QByteArray Service::reply_to(QByteArray message) {

    QByteArray ret;
    QDataStream stream(&ret, QIODevice::WriteOnly);

    QString m = QString(message);

    if(m == "get_all_departments") {

        chronos::Database db;
        QList<chronos::Department> departments = db.get_departments();

        int size = departments.size();
        stream << size;
        for(auto d: departments) {
            stream << d.name();
        }
        
        return ret;
    }

    return QByteArray("I don't know.");

}

