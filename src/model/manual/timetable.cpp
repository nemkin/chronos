#include "timetable.h"

#include <stdexcept>
#include <sstream>
#include <vector>

using namespace chronos;

Timetable::Timetable(
) :
    _parallel(1) {

}

Timetable::Timetable(
    int p_id
) : 
    _id(p_id),
    _parallel(1) {
    
}

int Timetable::id() const {

    return _id;
}

unsigned int Timetable::parallel() {

    return _parallel;
}

void Timetable::set_parallel(unsigned int p_parallel) {

    _parallel = p_parallel;
}

bool Timetable::timeslot_already_filled(Proposal proposal) const {

    if(proposals.find(proposal.timeslot_id()) == proposals.end() ||
       proposals.at(proposal.timeslot_id()).size() == 0) {

        return false;
    }

    unsigned int current_parallel = proposals.at(proposal.timeslot_id()).size();

    if (proposals.at(proposal.timeslot_id())[0].class_type_id() == 1) {
        
        current_parallel *= _parallel;
    }

    if(proposal.class_type_id() == 1) {
        
        return 1 <= current_parallel;

    } else {

        return _parallel <= current_parallel;
    }
}

void Timetable::add(Proposal proposal) {

    if (timeslot_already_filled(proposal)) {
        
        throw std::runtime_error("Conflicting proposal: \n" + proposal.to_string());
    }

    proposals[proposal.timeslot_id()].push_back(proposal);
}

std::string Timetable::pad_to_column_width(std::string str) const {

    unsigned int _column_width = 22;

    if (_column_width <= str.length()) return str.substr(0,_column_width);
   
    unsigned int space_needed = _column_width - str.length();

    unsigned int pad_to_left = space_needed / 2; 
    unsigned int pad_to_right = space_needed / 2 + space_needed % 2; 

    std::string ret;

    for(unsigned int i=0; i<pad_to_left; ++i) {
        ret += " ";
    }

    ret += str;

    for(unsigned int i=0; i<pad_to_right; ++i) {
        ret += " ";
    }

    return ret;
}

std::string Timetable::to_string() const {

    std::vector<std::vector<std::vector<std::string>>> timetable;

    timetable.resize(6);
    for(unsigned int i=0; i<6; ++i) {
        timetable[i].resize(5);
        for(unsigned int j=0; j<5; ++j) {
            timetable[i][j].resize(5 * _parallel);
        }
    }

    for(unsigned int i=0; i<30; ++i) {

        if(proposals.find(i+1) == proposals.end()) continue;

        for(unsigned int j=0; j<proposals.at(i+1).size(); ++j) {

            timetable[i%6][i/6][j*5 + 1] = proposals.at(i+1).at(j).class_name();
            timetable[i%6][i/6][j*5 + 2] = proposals.at(i+1).at(j).room_name();
            timetable[i%6][i/6][j*5 + 3] = proposals.at(i+1).at(j).faculty_member_name();
            timetable[i%6][i/6][j*5 + 4] = proposals.at(i+1).at(j).year_name();
        }
    }

    std::stringstream ss;

    ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;
    ss << "|        MONDAY          |         TUESDAY        |        WEDNESDAY       |        THURSDAY        |         FRIDAY         |" << std::endl;
    ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;


    for(unsigned int i=0; i<6; ++i) {

        for(unsigned int k=0; k<5*_parallel; ++k) {

        ss << "| ";

            for(unsigned int j=0; j<5; ++j) {

                ss << pad_to_column_width(timetable[i][j][k]) << " | ";

            }

            ss << std::endl;
        } 

        ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;
    }
    
    return ss.str();
}

