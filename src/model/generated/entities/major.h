#pragma once

#ifndef __MAJOR__H__
#define __MAJOR__H__

#include <string>

namespace chronos {

class Major {

public:

    Major();

    Major(
        int p_id,
        std::string p_name,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    std::string name() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    std::string _name;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__MAJOR__H__

