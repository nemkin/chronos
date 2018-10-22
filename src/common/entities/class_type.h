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
        std::string p_name,
        int p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    int modified_timestamp() const;
    bool is_deleted() const;

    std::string to_string() const;     

private:

    int _id;
    std::string _name;
    int _modified_timestamp;
    bool _is_deleted;
    
};

}

#endif //__CLASS_TYPE__H__

