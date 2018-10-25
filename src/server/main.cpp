#include <iostream>

#include "model/generated/database/database.h"

int main(int argc, char *argv[]) {

    std::string user;
    std::string pass;

    std::cout<<"User: ";
    std::cin>>user;

    std::cout<<"Pass: ";
    std::cin>>pass;

    chronos::Database d(user, pass);
    
    d.test(); 
    d.destroy();
    d.init();

    std::vector<chronos::Department> departments = d.get_departments();

    for(auto dep: departments) {
         std::cout << dep.to_string() << std::endl;
    }
    
    return 0;
}
