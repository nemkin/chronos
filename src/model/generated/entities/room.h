#pragma once

#ifndef __ROOM__H__
#define __ROOM__H__

#include <string>

namespace chronos {

class Room {

public:

    Room();

    Room(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        int p_id,
        std::string p_name,
        int p_size,
        int p_room_type_id,
        int p_location_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    int id() const;
    std::string name() const;
    int size() const;
    int room_type_id() const;
    int location_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    int _id;
    std::string _name;
    int _size;
    int _room_type_id;
    int _location_id;

};

}

#endif //__ROOM__H__

