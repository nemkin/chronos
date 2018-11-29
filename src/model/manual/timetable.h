#pragma once

#ifndef __TIMETALBE__H__
#define __TIMETABLE__H__

#include <string>
#include <map>
#include <vector>

#include "model/manual/proposal.h"

namespace chronos {

class Timetable {

public:

    Timetable();

    Timetable(
        int p_id
    );

    int id() const;
    unsigned int parallel();
    void set_parallel(unsigned int p_parallel);

    bool timeslot_already_filled(Proposal proposal) const;
    void add(Proposal proposal); 
    std::string pad_to_column_width(std::string str) const;
    std::string to_string() const;

private:

    static const unsigned int _column_width = 22;

    int _id;
    unsigned int _parallel;
    std::map<int, std::vector<Proposal>> proposals;

};

}

#endif //__TIMETABLE__H__

