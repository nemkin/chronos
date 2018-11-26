#include "room.h"

#include <sstream>

using namespace chronos;

Room::Room(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _size_type(""),
    _location_id(0),
    _class_type_id(0) {

}

Room::Room(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    std::string p_size_type,
    int p_location_id,
    int p_class_type_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _size_type(p_size_type),
    _location_id(p_location_id),
    _class_type_id(p_class_type_id) {

}

int Room::id() const {

    return _id;
}

std::string Room::modified_timestamp() const {

    return _modified_timestamp;
}

bool Room::is_deleted() const {

    return _is_deleted;
}

std::string Room::name() const {

    return _name;
}

std::string Room::size_type() const {

    return _size_type;
}

int Room::location_id() const {

    return _location_id;
}

int Room::class_type_id() const {

    return _class_type_id;
}

std::string Room::to_string() const {

    std::stringstream ss;

    ss << "room                "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "size_type:          " << _size_type          << std::endl;
    ss << "location_id:        " << _location_id        << std::endl;
    ss << "class_type_id:      " << _class_type_id      << std::endl;

    return ss.str();
}

