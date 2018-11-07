#include "course.h"

#include <sstream>

using namespace chronos;

Course::Course(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _year_id(0),
    _department_id(0) {

}

Course::Course(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    int p_year_id,
    int p_department_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _year_id(p_year_id),
    _department_id(p_department_id) {

}

int Course::id() const {

    return _id;
}

std::string Course::modified_timestamp() const {

    return _modified_timestamp;
}

bool Course::is_deleted() const {

    return _is_deleted;
}

std::string Course::name() const {

    return _name;
}

int Course::year_id() const {

    return _year_id;
}

int Course::department_id() const {

    return _department_id;
}

std::string Course::to_string() const {

    std::stringstream ss;

    ss << "course              "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "year_id:            " << _year_id            << std::endl;
    ss << "department_id:      " << _department_id      << std::endl;

    return ss.str();
}

