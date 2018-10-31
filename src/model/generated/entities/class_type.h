#pragma once

#ifndef __CLASS_TYPE__H__
#define __CLASS_TYPE__H__

#include <string>

namespace chronos {

class ClassType {

public:

    ClassType();

    ClassType(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        int p_id,
        std::string p_name
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    int id() const;
    std::string name() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    int _id;
    std::string _name;

};

}

#endif //__CLASS_TYPE__H__

