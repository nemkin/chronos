#include "year.h"

#include <sstream>

using namespace chronos;

Year::Year(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name("") {

}

Year::Year(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name) {

}

int Year::id() const {

    return _id;
}

std::string Year::modified_timestamp() const {

    return _modified_timestamp;
}

bool Year::is_deleted() const {

    return _is_deleted;
}

std::string Year::name() const {

    return _name;
}

std::string Year::to_string() const {

    std::stringstream ss;

    ss << "year                "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;

    return ss.str();
}

