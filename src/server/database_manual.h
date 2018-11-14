#pragma once

#ifndef __DATABASE_MANUAL__H__
#define __DATABASE_MANUAL__H__

#include <string>

#include "model/generated/database/database.h"
#include "server/proposal.h"

namespace chronos {

class DatabaseManual : public Database {

public:

    DatabaseManual(
        std::string p_user,
        std::string p_pass,
        std::string p_host = "10.240.2.125",
        std::string p_database = "chronos"
    );

    std::vector<int> get_rooms_by_id_to_hold_class(int class_id);
    std::vector<int> get_faculty_members_by_id_licensed_to_teach_class(int class_id);
    int get_year_by_id_for_class(int class_id);

};

}

#endif //__DATABASE_MANUAL__H__

