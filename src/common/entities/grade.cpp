#include "grade.h"

#include <sstream>

using namespace chronos;

Grade::Grade(
) :
    _id(0),
    _name(""),
    _major_id(0),
    _modified_timestamp(""),
    _is_deleted(false) {

}

Grade::Grade(
    int p_id,
    std::string p_name,
    int p_major_id,
    std::string p_modified_timestamp,
    bool p_is_deleted
) :
    _id(p_id),
    _name(p_name),
    _major_id(p_major_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted) {

}

int Grade::id() const {

    return _id;
}

std::string Grade::name() const {

    return _name;
}

int Grade::major_id() const {

    return _major_id;
}

std::string Grade::modified_timestamp() const {

    return _modified_timestamp;
}

bool Grade::is_deleted() const {

    return _is_deleted;
}

std::string Grade::to_string() const {

    std::stringstream ss;

    ss << "grade               "                       << std::endl;
    ss << "id:                 " << id                 << std::endl;
    ss << "name:               " << name               << std::endl;
    ss << "major_id:           " << major_id           << std::endl;
    ss << "modified_timestamp: " << modified_timestamp << std::endl;
    ss << "is_deleted:         " << is_deleted         << std::endl;

    return ss.str();
}

