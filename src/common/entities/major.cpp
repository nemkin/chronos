#include "major.h"

#include <sstream>

using namespace chronos;

Major::Major(
) :
    _id(0),
    _name(""),
    _modified_timestamp(""),
    _is_deleted(false) {

}

Major::Major(
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

int Major::id() const {

    return _id;
}

std::string Major::name() const {

    return _name;
}

std::string Major::modified_timestamp() const {

    return _modified_timestamp;
}

bool Major::is_deleted() const {

    return _is_deleted;
}

std::string Major::to_string() const {

    std::stringstream ss;

    ss << "major               "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;

    return ss.str();
}

