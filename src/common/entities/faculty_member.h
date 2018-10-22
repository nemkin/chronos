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
        std::string p_name,
        int p_department_id,
        int p_modified_timestamp,
        bool _is_deleted
    );

    int id() const;
    std::string name() const;
    int department_id() const;
    int modified_timestamp() const;
    bool is_deleted() const;

    std::string to_string() const;
 
private:

    int _id;
    std::string _name;
    int _department_id;
    int _modified_timestamp;
    bool _is_deleted; 

};

}

#endif //__FACULTY_MEMBER__H__

