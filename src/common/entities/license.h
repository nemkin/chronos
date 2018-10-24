#pragma once

#ifndef __LICENSE__H__
#define __LICENSE__H__

#include <string>

namespace chronos {

class License {

public:

    License();

    License(
        int p_id,
        int p_course_id,
        int p_class_type_id,
        int p_faculty_member_id,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    int course_id() const;
    int class_type_id() const;
    int faculty_member_id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    int _course_id;
    int _class_type_id;
    int _faculty_member_id;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__LICENSE__H__

