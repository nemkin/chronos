#include "license.h"

#include <sstream>

using namespace chronos;

License::License(
) :
    _id(0),
    _course_id(0),
    _class_type_id(0),
    _faculty_member_id(0),
    _modified_timestamp(""),
    _is_deleted(false) {

}

License::License(
    int p_id,
    int p_course_id,
    int p_class_type_id,
    int p_faculty_member_id,
    std::string p_modified_timestamp,
    bool p_is_deleted
) :
    _id(p_id),
    _course_id(p_course_id),
    _class_type_id(p_class_type_id),
    _faculty_member_id(p_faculty_member_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted) {

}

int License::id() const {

    return _id;
}

int License::course_id() const {

    return _course_id;
}

int License::class_type_id() const {

    return _class_type_id;
}

int License::faculty_member_id() const {

    return _faculty_member_id;
}

std::string License::modified_timestamp() const {

    return _modified_timestamp;
}

bool License::is_deleted() const {

    return _is_deleted;
}

std::string License::to_string() const {

    std::stringstream ss;

    ss << "license             "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "course_id:          " << _course_id          << std::endl;
    ss << "class_type_id:      " << _class_type_id      << std::endl;
    ss << "faculty_member_id:  " << _faculty_member_id  << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;

    return ss.str();
}

