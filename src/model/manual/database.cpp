#include "database.h"

#include <iostream>

using namespace chronos;

Database::Database(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
):
    DatabasePartial(
        p_user,
        p_password,
        p_host,
        p_database) {

}

std::vector<int> Database::get_rooms_by_id_to_hold_class(int class_id) {

    std::vector<int> ret;

    try {
        
        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec(
            "SELECT rooms.id "
            "FROM rooms, classes "
            "WHERE "
            "rooms.class_type_id = classes.class_type_id AND "
            "classes.id = " + std::to_string(class_id) + ";"
        ));

        for(auto i = r.begin(); i != r.end(); ++i) {

            ret.push_back(i[0].as<int>());
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<int> Database::get_faculty_members_by_id_licensed_to_teach_class(int class_id) {

    std::vector<int> ret;

    try {
        
        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec(
            "SELECT faculty_members.id "
            "FROM "
            "classes, faculty_members, licenses "
            "WHERE "
            "licenses.course_id = classes.course_id AND "
            "licenses.class_type_id = classes.class_type_id AND "
            "licenses.faculty_member_id = faculty_members.id AND "
            "classes.id = " + std::to_string(class_id) + ";"
        ));

        for(auto i = r.begin(); i != r.end(); ++i) {

            ret.push_back(i[0].as<int>());
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

int Database::get_year_by_id_for_class(int class_id) {

    try {
        
        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec(
            "SELECT courses.year_id "
            "FROM courses, classes "
            "WHERE "
            "courses.id = classes.course_id AND "
            "classes.id = " + std::to_string(class_id) + ";"
        ));

        return r[0][0].as<int>();

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return 0;
}

