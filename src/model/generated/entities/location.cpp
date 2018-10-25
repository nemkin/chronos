#include "location.h"

#include <sstream>

using namespace chronos;

Location::Location(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _latitude(0.0),
    _longitude(0.0) {

}

Location::Location(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    double p_latitude,
    double p_longitude
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _latitude(p_latitude),
    _longitude(p_longitude) {

}

int Location::id() const {

    return _id;
}

std::string Location::modified_timestamp() const {

    return _modified_timestamp;
}

bool Location::is_deleted() const {

    return _is_deleted;
}

std::string Location::name() const {

    return _name;
}

double Location::latitude() const {

    return _latitude;
}

double Location::longitude() const {

    return _longitude;
}

std::string Location::to_string() const {

    std::stringstream ss;

    ss << "location            "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "latitude:           " << _latitude           << std::endl;
    ss << "longitude:          " << _longitude          << std::endl;

    return ss.str();
}

