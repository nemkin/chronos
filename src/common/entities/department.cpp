#include "department.h"

#include <sstream>

using namespace chronos;

Department::Department(
) :
    _id(0),
    _name(""),
    _modified_timestamp(""),
    _is_deleted(false) {

}

Department::Department(
    int p_id,
    std::string p_name,
    std::string p_modified_timestamp,
    bool p_is_deleted
) :
    _id(p_id),
    _name(p_name),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted) {

}

int Department::id() const {

    return _id;
}

std::string Department::name() const {

    return _name;
}

std::string Department::modified_timestamp() const {

    return _modified_timestamp;
}

bool Department::is_deleted() const {

    return _is_deleted;
}

std::string Department::to_string() const {

    std::stringstream ss;

    ss << "department          "                       << std::endl;
    ss << "id:                 " << id                 << std::endl;
    ss << "name:               " << name               << std::endl;
    ss << "modified_timestamp: " << modified_timestamp << std::endl;
    ss << "is_deleted:         " << is_deleted         << std::endl;

    return ss.str();
}

