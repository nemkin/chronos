#include "database_service.h"

#include <iostream>
#include <stdexcept>

using namespace chronos;

Database* DatabaseService::_instance = nullptr;
std::string DatabaseService::_last_error = "";

void DatabaseService::init(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
) {

    destroy();

    try {

        DatabaseService::_instance = new Database(
            p_user,
            p_password,
            p_host,
            p_database
        );

    } catch (std::exception& e) {

        DatabaseService::_last_error = e.what();
        std::cerr << _last_error << std::endl;
        destroy();
    }
}

void DatabaseService::destroy() {

    if(is_initialized()) {
    
        delete DatabaseService::_instance;
        DatabaseService::_instance = nullptr;
    }
}


bool DatabaseService::is_initialized() {
    
    return DatabaseService::_instance != nullptr;
}

Database& DatabaseService::instance() {

    if (is_initialized()) {
    
        return *DatabaseService::_instance;
    }

    throw std::runtime_error("Trying to use database instance but it is not initialized!");
}

std::string DatabaseService::last_error() {

    return DatabaseService::_last_error;
}

