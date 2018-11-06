#include "room_type.h"

#include <sstream>

using namespace chronos;

RoomType::RoomType(
) :
    _id(0),
    _modified_timestamp(""),
    _is_deleted(false),
    _name("") {

}

RoomType::RoomType(
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

int RoomType::id() const {

    return _id;
}

std::string RoomType::modified_timestamp() const {

    return _modified_timestamp;
}

bool RoomType::is_deleted() const {

    return _is_deleted;
}

std::string RoomType::name() const {

    return _name;
}

std::string RoomType::to_string() const {

    std::stringstream ss;

    ss << "room_type           "                        << std::endl;
    ss << "id:                 " << _id                 << std::endl;
    ss << "modified_timestamp: " << _modified_timestamp << std::endl;
    ss << "is_deleted:         " << _is_deleted         << std::endl;
    ss << "name:               " << _name               << std::endl;

    return ss.str();
}

