#pragma once

#ifndef __PROPOSAL__H__
#define __PROPOSAL__H__

#include <string>
#include <vector>

namespace chronos {

class Proposal {

public:

    Proposal();

    Proposal(
        int timeslot_id,
        int year_id,
        int class_id,
        std::vector<int> room_ids,
        std::vector<int> faculty_member_ids,
        std::string timeslot_name,
        std::string year_name,
        std::string class_name,
        std::vector<std::string> room_names,
        std::vector<std::string> faculty_member_names
    );

    int timeslot_id() const;
    int year_id() const;
    int class_id() const;
    std::vector<int> room_ids() const;
    std::vector<int> faculty_member_ids() const;
    std::string timeslot_name() const;
    std::string year_name() const;
    std::string class_name() const;
    std::vector<std::string> room_names() const;
    std::string room_names_string() const;
    std::vector<std::string> faculty_member_names() const;
    std::string faculty_member_names_string() const;
    std::string to_string() const;

private:

    int _timeslot_id;
    int _year_id;
    int _class_id;
    std::vector<int> _room_ids;
    std::vector<int> _faculty_member_ids;
    std::string _timeslot_name;
    std::string _year_name;
    std::string _class_name;
    std::vector<std::string> _room_names;
    std::vector<std::string> _faculty_member_names;

};

}

#endif //__PROPOSAL__H__

