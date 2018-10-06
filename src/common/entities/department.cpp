#include "department.h"

using namespace chronos;

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
