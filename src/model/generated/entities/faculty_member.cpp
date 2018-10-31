#include "faculty_member.h"

#include <sstream>

using namespace chronos;

FacultyMember::FacultyMember(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _id(0),
    _name(""),
    _department_id(0) {

}

FacultyMember::FacultyMember(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    int p_id,
    std::string p_name,
    int p_department_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _id(p_id),
    _name(p_name),
    _department_id(p_department_id) {

}

int FacultyMember::id() const {

    return _id;
}

std::string FacultyMember::modified_timestamp() const {

    return _modified_timestamp;
}

bool FacultyMember::is_deleted() const {

    return _is_deleted;
}

int FacultyMember::id() const {

    return _id;
}

std::string FacultyMember::name() const {

    return _name;
}

int FacultyMember::department_id() const {

    return _department_id;
}

std::string FacultyMember::to_string() const {

    std::stringstream ss;

    ss << "faculty_member      "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "department_id:      " << _department_id      << std::endl;

    return ss.str();
}

