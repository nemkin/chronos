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
        std::string p_name,
        int p_student_count,
        int p_location_id,
        int p_class_type_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string name() const;
    int student_count() const;
    int location_id() const;
    int class_type_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    std::string _name;
    int _student_count;
    int _location_id;
    int _class_type_id;

};

}

#endif //__ROOM__H__

