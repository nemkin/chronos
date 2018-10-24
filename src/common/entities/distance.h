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
        int p_location_id_1,
        int p_location_id_2,
        double p_distance_minutes,
        std::string p_modified_timestamp,
        bool p_is_deleted
    );

    int id() const;
    int location_id_1() const;
    int location_id_2() const;
    double distance_minutes() const;
    std::string modified_timestamp() const;
    bool is_deleted() const;
    std::string to_string() const;

private:

    int _id;
    int _location_id_1;
    int _location_id_2;
    double _distance_minutes;
    std::string _modified_timestamp;
    bool _is_deleted;

};

}

#endif //__DISTANCE__H__

