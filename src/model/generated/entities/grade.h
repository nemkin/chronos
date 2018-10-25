#pragma once

#ifndef __GRADE__H__
#define __GRADE__H__

#include <string>

namespace chronos {

class Grade {

public:

    Grade();

    Grade(
        int p_id,
        std::string p_name,
        int p_major_id,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    int major_id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    std::string _name;
    int _major_id;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__GRADE__H__

