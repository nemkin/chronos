#pragma once

#ifndef __PROPOSAL__H__
#define __PROPOSAL__H__

#include <string>

namespace chronos {

class Proposal {

public:

    Proposal();

    Proposal(
        int timeslot_id,
        int year_id,
        int class_id,
        int room_ids,
        int faculty_member_ids,
        int class_type_id,
        std::string timeslot_name,
        std::string year_name,
        std::string class_name,
        std::string room_name,
        std::string faculty_member_name
    );

    int timeslot_id() const;
    int year_id() const;
    int class_id() const;
    int room_id() const;
    int faculty_member_id() const;
    int class_type_id() const;
    std::string timeslot_name() const;
    std::string year_name() const;
    std::string class_name() const;
    std::string room_name() const;
    std::string faculty_member_name() const;
    std::string to_string() const;

private:

    int _timeslot_id;
    int _year_id;
    int _class_id;
    int _room_id;
    int _faculty_member_id;
    int _class_type_id;
    std::string _timeslot_name;
    std::string _year_name;
    std::string _class_name;
    std::string _room_name;
    std::string _faculty_member_name;

};

}

#endif //__PROPOSAL__H__

