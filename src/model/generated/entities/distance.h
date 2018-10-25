#pragma once

#ifndef __DISTANCE__H__
#define __DISTANCE__H__

#include <string>

namespace chronos {

class Distance {

public:

    Distance();

    Distance(
        int p_id,
        std::string p_modified_timestamp,
        bool p_is_deleted,
        double p_distance_minutes,
        int p_location_id_1,
        int p_location_id_2
    );

    int id() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    double distance_minutes() const;
    int location_id_1() const;
    int location_id_2() const;
    std::string to_string() const;

private:

    int _id;
    std::string _modified_timestamp;
    bool _is_deleted;
    double _distance_minutes;
    int _location_id_1;
    int _location_id_2;

};

}

#endif //__DISTANCE__H__

