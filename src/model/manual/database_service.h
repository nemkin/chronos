#pragma once

#ifndef __DATABASE_SERVICE__H__
#define __DATABASE_SERVICE__H__

#include <string>

#include "model/manual/database.h"

namespace chronos {

class DatabaseService {

public:

    static void init(
        std::string p_user,
        std::string p_password,
        std::string p_host,
        std::string p_database
    );

    static void destroy();
    static bool is_initialized();

    static Database& instance();

private:

    static Database* _instance;
};

}

#endif //__DATABASE_SERVICE__H__

