#include "database_manual.h"

#include <iostream>

using namespace chronos;

DatabaseManual::DatabaseManual(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
):
    Database(
        p_user,
        p_password,
        p_host,
        p_database) {

}

std::vector<int> DatabaseManual::get_rooms_by_id_to_hold_class(int class_id) {

    std::vector<int> ret;

    try {
        
        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec(
            "SELECT rooms.id"
            "FROM rooms, classes"
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

std::vector<int> DatabaseManual::get_faculty_members_by_id_licensed_to_teach_class(int class_id) {

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

std::vector<Proposal> DatabaseManual::get_proposals() {

    std::vector<Proposal> ret;

    try {
        
        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec(
            "SELECT "
            "timeslots.id, years.id, classes.id, rooms.id, faculty_members.id, "
            "timeslots.name, years.name, classes.name, rooms.name, faculty_members.name "
            "FROM "
            "timeslots, years, departments, courses, class_types, locations, rooms, classes, faculty_members, licenses "
            "WHERE "
            "courses.year_id = years.id AND "
            "courses.department_id = departments.id AND "
            "rooms.location_id = locations.id AND "
            "rooms.class_type_id = class_types.id AND "
            "classes.class_type_id = class_types.id AND "
            "classes.course_id = courses.id AND "
            "faculty_members.department_id = departments.id AND "
            "licenses.course_id = courses.id AND "
            "licenses.class_type_id = class_types.id AND "
            "licenses.faculty_member_id = faculty_members.id;"
        ));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Proposal p(
                i[0].as<int>(), // timeslot_id
                i[1].as<int>(), // year_id
                i[2].as<int>(), // class_id
                i[3].as<int>(), // room_id
                i[4].as<int>(), // faculty_member_id
                i[5].as<std::string>(), // timeslot_name
                i[6].as<std::string>(), // year_name
                i[7].as<std::string>(), // class_name
                i[8].as<std::string>(), // room_name
                i[9].as<std::string>()  // faculty_member_name
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

