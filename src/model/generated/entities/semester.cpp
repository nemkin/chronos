#include "semester.h"

#include <sstream>

using namespace chronos;

Semester::Semester(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _id(0),
    _name(""),
    _semester_type_id(0) {

}

Semester::Semester(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    int p_id,
    std::string p_name,
    int p_semester_type_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _id(p_id),
    _name(p_name),
    _semester_type_id(p_semester_type_id) {

}

int Semester::id() const {

    return _id;
}

std::string Semester::modified_timestamp() const {

    return _modified_timestamp;
}

bool Semester::is_deleted() const {

    return _is_deleted;
}

int Semester::id() const {

    return _id;
}

std::string Semester::name() const {

    return _name;
}

int Semester::semester_type_id() const {

    return _semester_type_id;
}

std::string Semester::to_string() const {

    std::stringstream ss;

    ss << "semester            "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "semester_type_id:   " << _semester_type_id   << std::endl;

    return ss.str();
}

