#pragma once

#ifndef __DATABASE__H__
#define __DATABASE__H__

#include <string>
#include <vector>

#include <pqxx/pqxx>

#include "model/generated/entities/department.h"

namespace chronos {

class Database {

public:

    Database(
        std::string user_name,
        std::string password,
        std::string host_name = "localhost",
        std::string database_name = "chronos"
    );

    std::vector<Department> get_departments();

    void test();
    void init();
    void drop();

private:

    pqxx::connection _db;
};

}

#endif //__DATABASE__H__

