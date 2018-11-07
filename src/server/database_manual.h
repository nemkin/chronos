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
        std::string p_host = "localhost",
        std::string p_database = "chronos"
    );

    std::vector<Proposal> get_proposals();

};

}

#endif //__DATABASE_MANUAL__H__

