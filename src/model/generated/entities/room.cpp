#include "room.h"

#include <sstream>

using namespace chronos;

Room::Room(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name(""),
    _size(0),
    _room_type_id(0),
    _location_id(0) {

}

Room::Room(
    int p_id,
    std::string p_modified_timestamp,
    bool p_is_deleted,
    std::string p_name,
    int p_size,
    int p_room_type_id,
    int p_location_id
) :
    _id(p_id),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted),
    _name(p_name),
    _size(p_size),
    _room_type_id(p_room_type_id),
    _location_id(p_location_id) {

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

int Room::size() const {

    return _size;
}

int Room::room_type_id() const {

    return _room_type_id;
}

int Room::location_id() const {

    return _location_id;
}

std::string Room::to_string() const {

    std::stringstream ss;

    ss << "room                "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;
    ss << "size:               " << _size               << std::endl;
    ss << "room_type_id:       " << _room_type_id       << std::endl;
    ss << "location_id:        " << _location_id        << std::endl;

    return ss.str();
}

