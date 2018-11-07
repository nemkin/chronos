#include "timeslot.h"

#include <sstream>

using namespace chronos;

Timeslot::Timeslot(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name("") {

}

Timeslot::Timeslot(
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

int Timeslot::id() const {

    return _id;
}

std::string Timeslot::modified_timestamp() const {

    return _modified_timestamp;
}

bool Timeslot::is_deleted() const {

    return _is_deleted;
}

std::string Timeslot::name() const {

    return _name;
}

std::string Timeslot::to_string() const {

    std::stringstream ss;

    ss << "timeslot            "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;

    return ss.str();
}

