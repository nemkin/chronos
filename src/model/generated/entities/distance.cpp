#include "distance.h"

#include <sstream>

using namespace chronos;

Distance::Distance(
) :
    _id(0),
    _distance_minutes(0.0),
    _location_id_1(0),
    _location_id_2(0),
    _modified_timestamp(""),
    _is_deleted(false) {

}

Distance::Distance(
    int p_id,
    double p_distance_minutes,
    int p_location_id_1,
    int p_location_id_2,
    std::string p_modified_timestamp,
    bool p_is_deleted
) :
    _id(p_id),
    _distance_minutes(p_distance_minutes),
    _location_id_1(p_location_id_1),
    _location_id_2(p_location_id_2),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted) {

}

int Distance::id() const {

    return _id;
}

double Distance::distance_minutes() const {

    return _distance_minutes;
}

int Distance::location_id_1() const {

    return _location_id_1;
}

int Distance::location_id_2() const {

    return _location_id_2;
}

std::string Distance::modified_timestamp() const {

    return _modified_timestamp;
}

bool Distance::is_deleted() const {

    return _is_deleted;
}

std::string Distance::to_string() const {

    std::stringstream ss;

    ss << "distance            "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "distance_minutes:   " << _distance_minutes   << std::endl;
    ss << "location_id_1:      " << _location_id_1      << std::endl;
    ss << "location_id_2:      " << _location_id_2      << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;

    return ss.str();
}

