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

std::vector<Major> Database::get_majors() {

    std::vector<Major> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM majors;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Major p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>() // major_id
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>() // semester_type_id
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<std::string>() // short_name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // grade_id
                i[5].as<int>() // department_id
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // size
                i[5].as<int>(), // room_type_id
                i[6].as<int>() // location_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Class> Database::get_classes() {

    std::vector<Class> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM classes;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Class p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // lesson_count
                i[5].as<std::string>(), // regularity
                i[6].as<int>(), // maximum_student_count
                i[7].as<int>(), // class_type_id
                i[8].as<int>() // course_id
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>() // department_id
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
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<int>(), // course_id
                i[4].as<int>(), // class_type_id
                i[5].as<int>() // faculty_member_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

void Database::test() {

    if(_db.is_open()) {

        std::cout << "Connection successful!" << std::endl;

    } else {

        std::cout << "Connection failed." << std::endl;
    }
}

void Database::init() {

    std::vector<std::string> creates;

    creates.push_back(
        "CREATE TABLE majors ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE grades ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "major_id INTEGER REFERENCES majors(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semester_types ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semesters ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "semester_type_id INTEGER REFERENCES semester_types(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE departments ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "short_name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE courses ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "grade_id INTEGER REFERENCES grades(id) NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE class_types ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE locations ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE room_types ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE rooms ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "size INTEGER NOT NULL, "
            "room_type_id INTEGER REFERENCES room_types(id) NOT NULL, "
            "location_id INTEGER REFERENCES locations(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE classes ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "lesson_count INTEGER NOT NULL, "
            "regularity TEXT NOT NULL, "
            "maximum_student_count INTEGER NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE faculty_members ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE licenses ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "faculty_member_id INTEGER REFERENCES faculty_members(id) NOT NULL);"
    );

    try {

        pqxx::work w(_db);

        for(auto create : creates) {

            w.exec(create);
        }

        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

void Database::destroy() {

    std::vector<std::string> drops;

    drops.push_back("DROP TABLE majors CASCADE;");
    drops.push_back("DROP TABLE grades CASCADE;");
    drops.push_back("DROP TABLE semester_types CASCADE;");
    drops.push_back("DROP TABLE semesters CASCADE;");
    drops.push_back("DROP TABLE departments CASCADE;");
    drops.push_back("DROP TABLE courses CASCADE;");
    drops.push_back("DROP TABLE class_types CASCADE;");
    drops.push_back("DROP TABLE locations CASCADE;");
    drops.push_back("DROP TABLE room_types CASCADE;");
    drops.push_back("DROP TABLE rooms CASCADE;");
    drops.push_back("DROP TABLE classes CASCADE;");
    drops.push_back("DROP TABLE faculty_members CASCADE;");
    drops.push_back("DROP TABLE licenses CASCADE;");

    try {

        pqxx::work w(_db);

        for(auto drop : drops) {
            
            w.exec(drop);
        }

        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

