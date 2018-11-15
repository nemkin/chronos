#include "proposal.h" 
#include <sstream>

using namespace chronos;

Proposal::Proposal(
) :
    _timeslot_id(0),
    _year_id(0),
    _class_id(0),
    _room_ids(),
    _faculty_member_ids(),
    _timeslot_name(""),
    _year_name(""),
    _class_name(""),
    _room_names(),
    _faculty_member_names() {

}

Proposal::Proposal(
    int p_timeslot_id,
    int p_year_id,
    int p_class_id,
    std::vector<int> p_room_ids,
    std::vector<int> p_faculty_member_ids,
    std::string p_timeslot_name,
    std::string p_year_name,
    std::string p_class_name,
    std::vector<std::string> p_room_names,
    std::vector<std::string> p_faculty_member_names
) :
    _timeslot_id(p_timeslot_id),
    _year_id(p_year_id),
    _class_id(p_class_id),
    _room_ids(p_room_ids),
    _faculty_member_ids(p_faculty_member_ids),
    _timeslot_name(p_timeslot_name),
    _year_name(p_year_name),
    _class_name(p_class_name),
    _room_names(p_room_names),
    _faculty_member_names(p_faculty_member_names) {

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

std::vector<int> Proposal::room_ids() const {

    return _room_ids;
}

std::vector<int> Proposal::faculty_member_ids() const {

    return _faculty_member_ids;
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

std::vector<std::string> Proposal::room_names() const {

    return _room_names;
}

std::string Proposal::room_names_string() const {

    std::stringstream ss;

    for(int i=0; i<_room_names.size(); ++i) {
        ss << _room_names[i] << ((i == _room_names.size() -1) ? "" : ", ");
    }

    return ss.str();
}

std::vector<std::string> Proposal::faculty_member_names() const {

    return _faculty_member_names;
}

std::string Proposal::faculty_member_names_string() const {

    std::stringstream ss;

    for(int i=0; i<_faculty_member_names.size(); ++i) {
        ss << _faculty_member_names[i] << ((i == _faculty_member_names.size() -1) ? "" : ", ");
    }

    return ss.str();
}

std::string Proposal::to_string() const {

    std::stringstream ss;

    ss << "proposal              "                                  << std::endl;
    ss << "timeslot_name:        " << _timeslot_name                << std::endl;
    ss << "year_name:            " << _year_name                    << std::endl;
    ss << "class_name:           " << _class_name                   << std::endl;
    ss << "room_names:           " << room_names_string()           << std::endl;
    ss << "faculty_member_names: " << faculty_member_names_string() << std::endl;

    return ss.str();
}

