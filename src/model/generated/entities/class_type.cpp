#include "class_type.h"

#include <sstream>

using namespace chronos;

ClassType::ClassType(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _id(0),
    _name("") {

}

ClassType::ClassType(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    int p_id,
    std::string p_name
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _id(p_id),
    _name(p_name) {

}

int ClassType::id() const {

    return _id;
}

std::string ClassType::modified_timestamp() const {

    return _modified_timestamp;
}

bool ClassType::is_deleted() const {

    return _is_deleted;
}

int ClassType::id() const {

    return _id;
}

std::string ClassType::name() const {

    return _name;
}

std::string ClassType::to_string() const {

    std::stringstream ss;

    ss << "class_type          "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "name:               " << _name               << std::endl;

    return ss.str();
}

