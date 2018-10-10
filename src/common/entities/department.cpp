#include "department.h"

#include <QVariant>

using namespace chronos;

Department::Department() :
    _id(0),
    _name(""),
    _timestamp(0),
    _is_deleted(false) {

}

Department::Department(
    int p_id,
    QString p_name,
    int p_timestamp,
    bool p_is_deleted
) : 
    _id(p_id),
    _name(p_name),
    _timestamp(p_timestamp),
    _is_deleted(p_is_deleted) {

}

QString Department::name() const {

    return _name;
} 

QJsonObject Department::to_json() {

    QJsonObject ret;

    ret.insert("id", QJsonValue::fromVariant(QVariant(_id)));
    ret.insert("name", QJsonValue::fromVariant(_name));
    ret.insert("timestamp", QJsonValue::fromVariant(_timestamp));
    ret.insert("is_deleted", QJsonValue::fromVariant(_is_deleted));

    return ret;
}

Department Department::from_json(QJsonObject json) {

    int id = json["id"].toInt();
    QString name = json["name"].toString();
    int timestamp = json["timestamp"].toInt();
    bool is_deleted = json["is_deleted"].toBool();

    return Department(id, name, timestamp, is_deleted);
}

