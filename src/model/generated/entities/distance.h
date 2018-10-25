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
        double p_distance_minutes,
        int p_location_id_1,
        int p_location_id_2,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    double distance_minutes() const;
    int location_id_1() const;
    int location_id_2() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    double _distance_minutes;
    int _location_id_1;
    int _location_id_2;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__DISTANCE__H__

