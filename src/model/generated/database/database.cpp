#include "database.h"

#include <iostream>

using namespace chronos;

Database::Database(
    std::string user,
    std::string password,
    std::string host,
    std::string database
):
    _db(
        "host = " + host + " "
        "dbname = " + database + " "
        "user = " + user + " "
        "password = " + password) {

}

std::vector<Class> Database::get_classes() {

    std::vector<Class> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM classes;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Class p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // lesson_count
                i[3].as<int>(), // regularity
                i[4].as<int>(), // maximum_student_count
                i[5].as<int>(), // class_type_id
                i[6].as<int>(), // course_id
                i[7].as<std::string>(), // modified_timestamp
                i[8].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<ClassType> Database::get_class_types() {

    std::vector<ClassType> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM class_types;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            ClassType p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<std::string>(), // modified_timestamp
                i[3].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Course> Database::get_courses() {

    std::vector<Course> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM courses;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Course p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // grade_id
                i[3].as<std::string>(), // modified_timestamp
                i[4].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Department> Database::get_departments() {

    std::vector<Department> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM departments;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Department p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<std::string>(), // modified_timestamp
                i[3].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Distance> Database::get_distances() {

    std::vector<Distance> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM distances;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Distance p(
                i[0].as<int>(), // id
                i[1].as<double>(), // distance_minutes
                i[2].as<int>(), // location_id_1
                i[3].as<int>(), // location_id_2
                i[4].as<std::string>(), // modified_timestamp
                i[5].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<FacultyMember> Database::get_faculty_members() {

    std::vector<FacultyMember> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM faculty_members;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            FacultyMember p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // department_id
                i[3].as<std::string>(), // modified_timestamp
                i[4].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Grade> Database::get_grades() {

    std::vector<Grade> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM grades;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Grade p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // major_id
                i[3].as<std::string>(), // modified_timestamp
                i[4].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<License> Database::get_licenses() {

    std::vector<License> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM licenses;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            License p(
                i[0].as<int>(), // id
                i[1].as<int>(), // course_id
                i[2].as<int>(), // class_type_id
                i[3].as<int>(), // faculty_member_id
                i[4].as<std::string>(), // modified_timestamp
                i[5].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Location> Database::get_locations() {

    std::vector<Location> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM locations;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Location p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<double>(), // latitude
                i[3].as<double>(), // longitude
                i[4].as<std::string>(), // modified_timestamp
                i[5].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Major> Database::get_majors() {

    std::vector<Major> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM majors;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Major p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<std::string>(), // modified_timestamp
                i[3].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Room> Database::get_rooms() {

    std::vector<Room> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM rooms;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Room p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // size
                i[3].as<int>(), // room_type_id
                i[4].as<std::string>(), // modified_timestamp
                i[5].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<RoomType> Database::get_room_types() {

    std::vector<RoomType> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM room_types;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            RoomType p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // size
                i[3].as<std::string>(), // modified_timestamp
                i[4].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Semester> Database::get_semesters() {

    std::vector<Semester> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM semesters;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Semester p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<int>(), // semester_type_id
                i[3].as<std::string>(), // modified_timestamp
                i[4].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<SemesterType> Database::get_semester_types() {

    std::vector<SemesterType> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM semester_types;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            SemesterType p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // name
                i[2].as<std::string>(), // modified_timestamp
                i[3].as<bool>() // is_deleted
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

