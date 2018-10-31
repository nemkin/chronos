#pragma once

#ifndef __FACULTY_MEMBER__H__
#define __FACULTY_MEMBER__H__

#include <string>

namespace chronos {

class FacultyMember {

public:

    FacultyMember();

    FacultyMember(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        int p_id,
        std::string p_name,
        int p_department_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    int id() const;
    std::string name() const;
    int department_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    int _id;
    std::string _name;
    int _department_id;

};

}

#endif //__FACULTY_MEMBER__H__

