#pragma once

#ifndef __TIMETALBE__H__
#define __TIMETABLE__H__

#include <string>
#include <map>

#include "model/manual/proposal.h"

namespace chronos {

class Timetable {

public:

    Timetable();

    Timetable(
        int p_id
    );

    int id() const;
    bool timeslot_already_filled(Proposal proposal) const;
    void add(Proposal proposal); 
    std::string pad_to_column_width(std::string str) const;
    std::string to_string() const;

private:

    static const int _column_width = 22;

    int _id;
    std::map<int, Proposal> proposals;

};

}

#endif //__TIMETABLE__H__

