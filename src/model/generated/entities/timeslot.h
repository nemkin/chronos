#pragma once

#ifndef __TIMESLOT__H__
#define __TIMESLOT__H__

#include <string>

namespace chronos {

class Timeslot {

public:

    Timeslot();

    Timeslot(
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

#endif //__TIMESLOT__H__

