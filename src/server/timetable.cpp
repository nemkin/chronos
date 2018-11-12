#include "timetable.h"

#include <stdexcept>
#include <sstream>
#include <vector>

using namespace chronos;

Timetable::Timetable() {

}

Timetable::Timetable(
    int p_id
) : 
    _id(p_id) {
    
}

int Timetable::id() const {

    return _id;
}

bool Timetable::timeslot_already_filled(Proposal proposal) const {

    return proposals.find(proposal.timeslot_id()) != proposals.end();
}

void Timetable::add(Proposal proposal) {

    if (timeslot_already_filled(proposal)) {
        
        throw std::runtime_error("Conflicting proposal: \n" + proposal.to_string());
    }

    proposals[proposal.timeslot_id()] = proposal;
}

std::string Timetable::pad_to_column_width(std::string str) const {

    int _column_width = 22;

    if (_column_width <= str.length()) return str.substr(0,_column_width);
   
    int space_needed = _column_width - str.length();

    int pad_to_left = space_needed / 2; 
    int pad_to_right = space_needed / 2 + space_needed % 2; 

    std::string ret;

    for(int i=0; i<pad_to_left; ++i) {
        ret += " ";
    }

    ret += str;

    for(int i=0; i<pad_to_right; ++i) {
        ret += " ";
    }

    return ret;
}

std::string Timetable::to_string() const {


    std::vector<std::vector<std::vector<std::string>>> timetable;

    timetable.resize(6);
    for(int i=0; i<6; ++i) {
        timetable[i].resize(5);
        for(int j=0; j<5; ++j) {
            timetable[i][j].resize(5);
        }
    }

    for(int i=0; i<30; ++i) {

        if(proposals.find(i+1) == proposals.end()) continue;

        timetable[i%6][i/6][0] = proposals.at(i+1).class_name();
    
    }

    std::stringstream ss;

    ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;
    ss << "|        MONDAY          |         TUESDAY        |        WEDNESDAY       |        THURSDAY        |         FRIDAY         |" << std::endl;
    ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;


    for(int i=0; i<6; ++i) {

        for(int k=0; k<5; ++k) {

        ss << "| ";

            for(int j=0; j<5; ++j) {

                ss << pad_to_column_width(timetable[i][j][k]) << " | ";

            }

            ss << std::endl;
        } 

        ss << "+------------------------+------------------------+------------------------+------------------------+------------------------+" << std::endl;
    }
    
    return ss.str();
}

