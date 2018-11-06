#include "department.h"

#include <sstream>

using namespace chronos;

Department::Department(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _short_name("") {

}

Department::Department(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    std::string p_short_name
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _short_name(p_short_name) {

}

int Department::id() const {

    return _id;
}

std::string Department::modified_timestamp() const {

    return _modified_timestamp;
}

bool Department::is_deleted() const {

    return _is_deleted;
}

std::string Department::name() const {

    return _name;
}

std::string Department::short_name() const {

    return _short_name;
}

std::string Department::to_string() const {

    std::stringstream ss;

    ss << "department          "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "short_name:         " << _short_name         << std::endl;

    return ss.str();
}

