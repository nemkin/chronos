#include "database_service.h"

#include <iostream>
#include <stdexcept>

using namespace chronos;

Database* DatabaseService::_instance = nullptr;

void DatabaseService::init(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
) {

    if(DatabaseService::_instance != nullptr) {
    
        delete DatabaseService::_instance;
    }

    try {

        DatabaseService::_instance = new Database(
            p_user,
            p_password,
            p_host,
            p_database
        );

    } catch (std::exception& e) {

        std::cout << e.what() << std::endl;
        DatabaseService::_instance = nullptr;
    }
}

void DatabaseService::destroy() {

    if(DatabaseService::_instance != nullptr) {
    
        delete DatabaseService::_instance;
    }
    
    DatabaseService::_instance = nullptr;
}


Database& DatabaseService::instance() {

    if (DatabaseService::_instance != nullptr) {
    
        return *DatabaseService::_instance;
    }

    throw std::runtime_error("Trying to use database instance but it is not initialized!");
}

