#pragma once

#ifndef __YEAR__H__
#define __YEAR__H__

#include <string>

namespace chronos {

class Year {

public:

    Year();

    Year(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        std::string p_name
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string name() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    std::string _name;

};

}

#endif //__YEAR__H__

