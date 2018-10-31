#pragma once

#ifndef __SEMESTER__H__
#define __SEMESTER__H__

#include <string>

namespace chronos {

class Semester {

public:

    Semester();

    Semester(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        int p_id,
        std::string p_name,
        int p_semester_type_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    int id() const;
    std::string name() const;
    int semester_type_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    int _id;
    std::string _name;
    int _semester_type_id;

};

}

#endif //__SEMESTER__H__

