#pragma once

#ifndef __COURSE__H__
#define __COURSE__H__

#include <string>

namespace chronos {

class Course {

public:

    Course();

    Course(
        int p_id,
        std::string p_name,
        int p_grade_id,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    int grade_id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    std::string _name;
    int _grade_id;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__COURSE__H__

