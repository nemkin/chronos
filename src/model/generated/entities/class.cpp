#include "class.h"

#include <sstream>

using namespace chronos;

Class::Class(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _lesson_count(0),
    _regularity(0),
    _maximum_student_count(0),
    _class_type_id(0),
    _course_id(0) {

}

Class::Class(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    int p_lesson_count,
    int p_regularity,
    int p_maximum_student_count,
    int p_class_type_id,
    int p_course_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _lesson_count(p_lesson_count),
    _regularity(p_regularity),
    _maximum_student_count(p_maximum_student_count),
    _class_type_id(p_class_type_id),
    _course_id(p_course_id) {

}

int Class::id() const {

    return _id;
}

std::string Class::modified_timestamp() const {

    return _modified_timestamp;
}

bool Class::is_deleted() const {

    return _is_deleted;
}

std::string Class::name() const {

    return _name;
}

int Class::lesson_count() const {

    return _lesson_count;
}

int Class::regularity() const {

    return _regularity;
}

int Class::maximum_student_count() const {

    return _maximum_student_count;
}

int Class::class_type_id() const {

    return _class_type_id;
}

int Class::course_id() const {

    return _course_id;
}

std::string Class::to_string() const {

    std::stringstream ss;

    ss << "class                  "                           << std::endl;
    ss << "id:                    " << _id                    << std::endl;
    ss << "modified_timestamp:    " << _modified_timestamp    << std::endl;
    ss << "is_deleted:            " << _is_deleted            << std::endl;
    ss << "name:                  " << _name                  << std::endl;
    ss << "lesson_count:          " << _lesson_count          << std::endl;
    ss << "regularity:            " << _regularity            << std::endl;
    ss << "maximum_student_count: " << _maximum_student_count << std::endl;
    ss << "class_type_id:         " << _class_type_id         << std::endl;
    ss << "course_id:             " << _course_id             << std::endl;

    return ss.str();
}

