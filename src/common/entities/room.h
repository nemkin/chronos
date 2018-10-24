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
        std::string p_name,
        int p_room_type_id,
        int p_size,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    int room_type_id() const;
    int size() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    std::string _name;
    int _room_type_id;
    int _size;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__ROOM__H__

