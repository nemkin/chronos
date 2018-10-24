#include "room.h"

#include <sstream>

using namespace chronos;

Room::Room(
) :
    _id(0),
    _name(""),
    _room_type_id(0),
    _size(0),
    _modified_timestamp(""),
    _is_deleted(false) {

}

Room::Room(
    int p_id,
    std::string p_name,
    int p_room_type_id,
    int p_size,
    std::string p_modified_timestamp,
    bool p_is_deleted
) :
    _id(p_id),
    _name(p_name),
    _room_type_id(p_room_type_id),
    _size(p_size),
    _modified_timestamp(p_modified_timestamp),
    _is_deleted(p_is_deleted) {

}

int Room::id() const {

    return _id;
}

std::string Room::name() const {

    return _name;
}

int Room::room_type_id() const {

    return _room_type_id;
}

int Room::size() const {

    return _size;
}

std::string Room::modified_timestamp() const {

    return _modified_timestamp;
}

bool Room::is_deleted() const {

    return _is_deleted;
}

std::string Room::to_string() const {

    std::stringstream ss;

    ss << "room                "                       << std::endl;
    ss << "id:                 " << id                 << std::endl;
    ss << "name:               " << name               << std::endl;
    ss << "room_type_id:       " << room_type_id       << std::endl;
    ss << "size:               " << size               << std::endl;
    ss << "modified_timestamp: " << modified_timestamp << std::endl;
    ss << "is_deleted:         " << is_deleted         << std::endl;

    return ss.str();
}

