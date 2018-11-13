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
        std::string p_modified_timestamp,
        bool p_is_deleted,
        std::string p_name,
        int p_student_count,
        int p_year_id,
        int p_department_id
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string name() const;
    int student_count() const;
    int year_id() const;
    int department_id() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    std::string _name;
    int _student_count;
    int _year_id;
    int _department_id;

};

}

#endif //__COURSE__H__

