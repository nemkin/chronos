#include "proposal.h" 

#include <sstream>

using namespace chronos;

Proposal::Proposal(
) :
    _timeslot_id(0),
    _year_id(0),
    _class_id(0),
    _room_id(0),
    _faculty_member_id(0),
    _class_type_id(0),
    _timeslot_name(""),
    _year_name(""),
    _class_name(""),
    _room_name(""),
    _faculty_member_name("") {

}

Proposal::Proposal(
    int p_timeslot_id,
    int p_year_id,
    int p_class_id,
    int p_room_id,
    int p_faculty_member_id,
    int p_class_type_id,
    std::string p_timeslot_name,
    std::string p_year_name,
    std::string p_class_name,
    std::string p_room_name,
    std::string p_faculty_member_name
) :
    _timeslot_id(p_timeslot_id),
    _year_id(p_year_id),
    _class_id(p_class_id),
    _room_id(p_room_id),
    _faculty_member_id(p_faculty_member_id),
    _class_type_id(p_class_type_id),
    _timeslot_name(p_timeslot_name),
    _year_name(p_year_name),
    _class_name(p_class_name),
    _room_name(p_room_name),
    _faculty_member_name(p_faculty_member_name) {

}

int Proposal::timeslot_id() const {

    return _timeslot_id;
}

int Proposal::year_id() const {

    return _year_id;
}

int Proposal::class_id() const {

    return _class_id;
}

int Proposal::room_id() const {

    return _room_id;
}

int Proposal::faculty_member_id() const {

    return _faculty_member_id;
}

int Proposal::class_type_id() const {

    return _class_type_id;
}

std::string Proposal::timeslot_name() const {

    return _timeslot_name;
}

std::string Proposal::year_name() const {

    return _year_name;
}

std::string Proposal::class_name() const {

    return _class_name;
}

std::string Proposal::room_name() const {

    return _room_name;
}

std::string Proposal::faculty_member_name() const {

    return _faculty_member_name;
}

std::string Proposal::to_string() const {

    std::stringstream ss;

    ss << "proposal             "                                  << std::endl;
    ss << "timeslot_name:       " << _timeslot_name                << std::endl;
    ss << "year_name:           " << _year_name                    << std::endl;
    ss << "class_name:          " << _class_name                   << std::endl;
    ss << "room_name:           " << _room_name                    << std::endl;
    ss << "faculty_member_name: " << _faculty_member_name          << std::endl;

    return ss.str();
}

