#include "database_partial.h"

#include <iostream>

using namespace chronos;

DatabasePartial::DatabasePartial(
    std::string p_user,
    std::string p_password,
    std::string p_host,
    std::string p_database
):
    _user(p_user),
    _db(
        "host = " + p_host + " "
        "dbname = " + p_database + " "
        "user = " + p_user + " "
        "password = " + p_password) {

}

std::vector<Timeslot> DatabasePartial::get_timeslots() {

    std::vector<Timeslot> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM timeslots;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Timeslot p(
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

std::vector<Location> DatabasePartial::get_locations() {

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

std::vector<ClassType> DatabasePartial::get_class_types() {

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

std::vector<Year> DatabasePartial::get_years() {

    std::vector<Year> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM years;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Year p(
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

std::vector<Room> DatabasePartial::get_rooms() {

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
                i[4].as<std::string>(), // size_type
                i[5].as<int>(), // location_id
                i[6].as<int>() // class_type_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Department> DatabasePartial::get_departments() {

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

std::vector<Course> DatabasePartial::get_courses() {

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
                i[4].as<int>(), // year_id
                i[5].as<int>() // department_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<Class> DatabasePartial::get_classes() {

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
                i[4].as<int>(), // count
                i[5].as<int>(), // class_type_id
                i[6].as<int>() // course_id
            );

            ret.push_back(p);
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::vector<FacultyMember> DatabasePartial::get_faculty_members() {

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

std::vector<License> DatabasePartial::get_licenses() {

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

std::map<int, Timeslot> DatabasePartial::get_timeslots_map() {

    std::map<int, Timeslot> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM timeslots;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Timeslot p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Location> DatabasePartial::get_locations_map() {

    std::map<int, Location> ret;

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

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, ClassType> DatabasePartial::get_class_types_map() {

    std::map<int, ClassType> ret;

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

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Year> DatabasePartial::get_years_map() {

    std::map<int, Year> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM years;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Year p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>() // name
            );

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Room> DatabasePartial::get_rooms_map() {

    std::map<int, Room> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM rooms;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Room p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<std::string>(), // size_type
                i[5].as<int>(), // location_id
                i[6].as<int>() // class_type_id
            );

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Department> DatabasePartial::get_departments_map() {

    std::map<int, Department> ret;

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

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Course> DatabasePartial::get_courses_map() {

    std::map<int, Course> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM courses;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Course p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // year_id
                i[5].as<int>() // department_id
            );

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, Class> DatabasePartial::get_classes_map() {

    std::map<int, Class> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM classes;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            Class p(
                i[0].as<int>(), // id
                i[1].as<std::string>(), // modified_timestamp
                i[2].as<bool>(), // is_deleted
                i[3].as<std::string>(), // name
                i[4].as<int>(), // count
                i[5].as<int>(), // class_type_id
                i[6].as<int>() // course_id
            );

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, FacultyMember> DatabasePartial::get_faculty_members_map() {

    std::map<int, FacultyMember> ret;

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

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

std::map<int, License> DatabasePartial::get_licenses_map() {

    std::map<int, License> ret;

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

            ret[p.id()] = p;
        }

    } catch (std::exception& e) {

        std::cerr << e.what() << std::endl;
    }

    return ret;
}

bool DatabasePartial::test() {

    if(_db.is_open()) {

        std::cerr << "Connection successful!" << std::endl;

    } else {

        std::cerr << "Connection failed." << std::endl;
    }

    return _db.is_open();
}

void DatabasePartial::init() {

    std::vector<std::string> creates;

    creates.push_back(
        "CREATE TABLE timeslots ( "
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
        "CREATE TABLE class_types ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE years ( "
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
            "size_type TEXT NOT NULL, "
            "location_id INTEGER REFERENCES locations(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL);"
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
            "year_id INTEGER REFERENCES years(id) NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE classes ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "count INTEGER NOT NULL, "
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

void DatabasePartial::fill() {

    std::vector<std::string> inserts;

    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'hetfo 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'hetfo 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'hetfo 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, 'hetfo 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, 'hetfo 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, 'kedd 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, 'kedd 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,8, 'kedd 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,9, 'kedd 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,10, 'kedd 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,11, 'szerda 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,12, 'szerda 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,13, 'szerda 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,14, 'szerda 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,15, 'szerda 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,16, 'csutortok 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,17, 'csutortok 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,18, 'csutortok 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,19, 'csutortok 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,20, 'csutortok 16:15 - 18:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,21, 'pentek 8:15 - 10:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,22, 'pentek 10:15 - 12:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,23, 'pentek 12:15 - 14:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,24, 'pentek 14:15 - 16:00');");
    inserts.push_back("INSERT INTO timeslots (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,25, 'pentek 16:15 - 18:00');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'A epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'CH epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'E epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, 'H epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, 'I epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, 'K epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, 'Q epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,8, 'R epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,9, 'T epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,10, 'V1 epulet');");
    inserts.push_back("INSERT INTO locations (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,11, 'F epulet');");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, 'eloadas');");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, 'gyakorlat');");
    inserts.push_back("INSERT INTO class_types (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, 'labor');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,1, '1. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,2, '2. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,3, '3. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,4, '4. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,5, '5. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,6, '6. felev');");
    inserts.push_back("INSERT INTO years (modified_timestamp,is_deleted,id,name) VALUES (current_timestamp,false,7, '7. felev');");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,1, 'IB028', 'XL', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,2, 'Q-I', 'XL', 7, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,3, 'E1B', 'XL', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,4, 'IB027', 'L', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,5, 'IB026', 'L', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,6, 'IB025', 'L', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,7, 'IE007', 'L', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,8, 'E1C', 'L', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,9, 'QBF08', 'M', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,10, 'QBF09', 'M', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,11, 'QBF12', 'M', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,12, 'E401', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,13, 'E402', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,14, 'E403', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,15, 'E404', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,16, 'E405', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,17, 'E406', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,18, 'E407', 'S', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,19, 'IB134', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,20, 'IB138', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,21, 'IB139', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,22, 'IB140', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,23, 'IB141', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,24, 'IB142', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,25, 'IB144', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,26, 'IB145', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,27, 'IB146', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,28, 'IB147', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,29, 'IB310', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,30, 'IB413', 'S', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,31, 'QA240', 'S', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,32, 'QAF14', 'S', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,33, 'QB105', 'S', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,34, 'QB311', 'S', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,35, 'QB331', 'S', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,36, 'R4A', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,37, 'R4B', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,38, 'R4C', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,39, 'R4I', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,40, 'R4J', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,41, 'R4K', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,42, 'R4L', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,43, 'R4M', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,44, 'R4N', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,45, 'R4O', 'S', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,size_type,location_id,class_type_id) VALUES (current_timestamp,false,46, 'R4P', 'S', 8, 3);");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,1, 'Automatizalasi es Alkalmazott Informatikai Tanszek', 'AUT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,2, 'Elektronikai Technologia Tanszek', 'ETT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,3, 'Elektronikus Eszkozok Tanszéke', 'EET');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,4, 'Halozati Rendszerek és Szolgaltatasok Tanszek', 'HIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,5, 'Iranyitastechnika es Informatika Tanszek', 'IIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,6, 'Merestechnika es Informacios Rendszerek Tanszek', 'MIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,7, 'Szamitastudomanyi es Informacioelmeleti Tanszek', 'SZIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,8, 'Szelessavu Hirkozles es Villamossagtan Tanszek', 'HVT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,9, 'Tavkozlesi es Mediainformatikai Tanszek', 'TMIT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,10, 'Villamos Energetika Tanszek', 'VET');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,11, 'Bolcsesz Tanszek', 'BTK');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,12, 'Analizis Tanszek', 'MAT');");
    inserts.push_back("INSERT INTO departments (modified_timestamp,is_deleted,id,name,short_name) VALUES (current_timestamp,false,13, 'Fizika Tanszek', 'FIZ');");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,1, 'Analizis 1', 1, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,2, 'A programozas alapjai 1', 1, 3);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,3, 'Bevezetes a szamitaselmeletbe 1', 1, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,4, 'Bevezeto fizika', 1, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,5, 'Bevezeto matematika', 1, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,6, 'Digitalis technika', 1, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,7, 'Fizika 1', 1, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,8, 'Mernok leszek', 1, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,9, 'Analizis 2', 2, 12);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,10, 'A programozas alapjai 2', 2, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,11, 'Bevezetes a szamitaselmeletbe 2', 2, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,12, 'Fizika 2', 2, 13);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,13, 'Rendszermodellezes', 2, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,14, 'Szamitogep architekturak', 2, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,15, 'A programozas alapjai 3', 3, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,16, 'Adatbazisok', 3, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,17, 'Kodolastechnika', 3, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,18, 'Kommunikacios halozatok 1', 3, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,19, 'Rendszerelmelet', 3, 8);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,20, 'Szoftvertechnologia', 3, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,21, 'Valoszinusegszamitas', 3, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,22, 'Algoritmuselmelet', 4, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,23, 'Kommunikacios halozatok 2', 4, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,24, 'Menedzsment es vallalkozasgazdasagtan', 4, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,25, 'Operacios rendszerek', 4, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,26, 'Szamitogepes grafika', 4, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,27, 'Szoftver projekt laboratorium', 4, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,28, 'Szoftvertechnikak', 4, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,29, 'IT eszkozok technologiaja', 5, 3);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,30, 'Mesterseges intelligencia', 5, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,31, 'Mikro- es makrookonomia', 5, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,32, 'Mobil- es webes szoftverek', 5, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,33, 'Uzleti jog', 5, 11);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,34, 'Informatikai rendszertervezes', 5, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,35, 'Ipari informatika', 5, 5);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,36, 'Informacios rendszerek uzemeltetese', 6, 9);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,37, 'IT biztonsag', 6, 4);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,38, 'Alkalmazasfejlesztesi kornyezetek', 6, 1);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,39, 'Intelligens elosztott rendszerek', 6, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,40, 'Rendszertervezes laboratorium 1', 6, 6);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,41, 'Deklarativ programozas', 7, 7);");
    inserts.push_back("INSERT INTO courses (modified_timestamp,is_deleted,id,name,year_id,department_id) VALUES (current_timestamp,false,42, 'Rendszertervezes laboratorium 2', 7, 6);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,1, 'Analizis 1 eloadas', 1, 1, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,2, 'Analizis 1 gyakorlat', 2, 1, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,3, 'Analizis 1 labor', 3, 1, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,4, 'A programozas alapjai 1 eloadas', 1, 2, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,5, 'A programozas alapjai 1 gyakorlat', 2, 2, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,6, 'A programozas alapjai 1 labor', 3, 2, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,7, 'Bevezetes a szamitaselmeletbe 1 eloadas', 1, 3, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,8, 'Bevezetes a szamitaselmeletbe 1 gyakorlat', 2, 3, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,9, 'Bevezetes a szamitaselmeletbe 1 labor', 3, 3, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,10, 'Bevezeto fizika eloadas', 1, 4, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,11, 'Bevezeto fizika gyakorlat', 2, 4, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,12, 'Bevezeto fizika labor', 3, 4, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,13, 'Bevezeto matematika eloadas', 1, 5, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,14, 'Bevezeto matematika gyakorlat', 2, 5, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,15, 'Bevezeto matematika labor', 3, 5, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,16, 'Digitalis technika eloadas', 1, 6, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,17, 'Digitalis technika gyakorlat', 2, 6, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,18, 'Digitalis technika labor', 3, 6, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,19, 'Fizika 1 eloadas', 1, 7, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,20, 'Fizika 1 gyakorlat', 2, 7, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,21, 'Fizika 1 labor', 3, 7, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,22, 'Mernok leszek eloadas', 1, 8, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,23, 'Mernok leszek gyakorlat', 2, 8, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,24, 'Mernok leszek labor', 3, 8, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,25, 'Analizis 2 eloadas', 1, 9, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,26, 'Analizis 2 gyakorlat', 2, 9, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,27, 'Analizis 2 labor', 3, 9, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,28, 'A programozas alapjai 2 eloadas', 1, 10, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,29, 'A programozas alapjai 2 gyakorlat', 2, 10, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,30, 'A programozas alapjai 2 labor', 3, 10, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,31, 'Bevezetes a szamitaselmeletbe 2 eloadas', 1, 11, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,32, 'Bevezetes a szamitaselmeletbe 2 gyakorlat', 2, 11, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,33, 'Bevezetes a szamitaselmeletbe 2 labor', 3, 11, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,34, 'Fizika 2 eloadas', 1, 12, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,35, 'Fizika 2 gyakorlat', 2, 12, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,36, 'Fizika 2 labor', 3, 12, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,37, 'Rendszermodellezes eloadas', 1, 13, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,38, 'Rendszermodellezes gyakorlat', 2, 13, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,39, 'Rendszermodellezes labor', 3, 13, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,40, 'Szamitogep architekturak eloadas', 1, 14, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,41, 'Szamitogep architekturak gyakorlat', 2, 14, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,42, 'Szamitogep architekturak labor', 3, 14, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,43, 'A programozas alapjai 3 eloadas', 1, 15, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,44, 'A programozas alapjai 3 gyakorlat', 2, 15, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,45, 'A programozas alapjai 3 labor', 3, 15, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,46, 'Adatbazisok eloadas', 1, 16, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,47, 'Adatbazisok gyakorlat', 2, 16, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,48, 'Adatbazisok labor', 3, 16, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,49, 'Kodolastechnika eloadas', 1, 17, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,50, 'Kodolastechnika gyakorlat', 2, 17, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,51, 'Kodolastechnika labor', 3, 17, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,52, 'Kommunikacios halozatok 1 eloadas', 1, 18, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,53, 'Kommunikacios halozatok 1 gyakorlat', 2, 18, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,54, 'Kommunikacios halozatok 1 labor', 3, 18, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,55, 'Rendszerelmelet eloadas', 1, 19, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,56, 'Rendszerelmelet gyakorlat', 2, 19, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,57, 'Rendszerelmelet labor', 3, 19, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,58, 'Szoftvertechnologia eloadas', 1, 20, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,59, 'Szoftvertechnologia gyakorlat', 2, 20, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,60, 'Szoftvertechnologia labor', 3, 20, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,61, 'Valoszinusegszamitas eloadas', 1, 21, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,62, 'Valoszinusegszamitas gyakorlat', 2, 21, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,63, 'Valoszinusegszamitas labor', 3, 21, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,64, 'Algoritmuselmelet eloadas', 1, 22, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,65, 'Algoritmuselmelet gyakorlat', 2, 22, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,66, 'Algoritmuselmelet labor', 3, 22, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,67, 'Kommunikacios halozatok 2 eloadas', 1, 23, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,68, 'Kommunikacios halozatok 2 gyakorlat', 2, 23, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,69, 'Kommunikacios halozatok 2 labor', 3, 23, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,70, 'Menedzsment es vallalkozasgazdasagtan eloadas', 1, 24, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,71, 'Menedzsment es vallalkozasgazdasagtan gyakorlat', 2, 24, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,72, 'Menedzsment es vallalkozasgazdasagtan labor', 3, 24, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,73, 'Operacios rendszerek eloadas', 1, 25, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,74, 'Operacios rendszerek gyakorlat', 2, 25, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,75, 'Operacios rendszerek labor', 3, 25, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,76, 'Szamitogepes grafika eloadas', 1, 26, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,77, 'Szamitogepes grafika gyakorlat', 2, 26, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,78, 'Szamitogepes grafika labor', 3, 26, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,79, 'Szoftver projekt laboratorium eloadas', 1, 27, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,80, 'Szoftver projekt laboratorium gyakorlat', 2, 27, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,81, 'Szoftver projekt laboratorium labor', 3, 27, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,82, 'Szoftvertechnikak eloadas', 1, 28, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,83, 'Szoftvertechnikak gyakorlat', 2, 28, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,84, 'Szoftvertechnikak labor', 3, 28, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,85, 'IT eszkozok technologiaja eloadas', 1, 29, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,86, 'IT eszkozok technologiaja gyakorlat', 2, 29, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,87, 'IT eszkozok technologiaja labor', 3, 29, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,88, 'Mesterseges intelligencia eloadas', 1, 30, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,89, 'Mesterseges intelligencia gyakorlat', 2, 30, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,90, 'Mesterseges intelligencia labor', 3, 30, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,91, 'Mikro- es makrookonomia eloadas', 1, 31, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,92, 'Mikro- es makrookonomia gyakorlat', 2, 31, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,93, 'Mikro- es makrookonomia labor', 3, 31, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,94, 'Mobil- es webes szoftverek eloadas', 1, 32, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,95, 'Mobil- es webes szoftverek gyakorlat', 2, 32, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,96, 'Mobil- es webes szoftverek labor', 3, 32, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,97, 'Uzleti jog eloadas', 1, 33, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,98, 'Uzleti jog gyakorlat', 2, 33, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,99, 'Uzleti jog labor', 3, 33, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,100, 'Informatikai rendszertervezes eloadas', 1, 34, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,101, 'Informatikai rendszertervezes gyakorlat', 2, 34, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,102, 'Informatikai rendszertervezes labor', 3, 34, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,103, 'Ipari informatika eloadas', 1, 35, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,104, 'Ipari informatika gyakorlat', 2, 35, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,105, 'Ipari informatika labor', 3, 35, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,106, 'Informacios rendszerek uzemeltetese eloadas', 1, 36, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,107, 'Informacios rendszerek uzemeltetese gyakorlat', 2, 36, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,108, 'Informacios rendszerek uzemeltetese labor', 3, 36, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,109, 'IT biztonsag eloadas', 1, 37, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,110, 'IT biztonsag gyakorlat', 2, 37, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,111, 'IT biztonsag labor', 3, 37, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,112, 'Alkalmazasfejlesztesi kornyezetek eloadas', 1, 38, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,113, 'Alkalmazasfejlesztesi kornyezetek gyakorlat', 2, 38, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,114, 'Alkalmazasfejlesztesi kornyezetek labor', 3, 38, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,115, 'Intelligens elosztott rendszerek eloadas', 1, 39, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,116, 'Intelligens elosztott rendszerek gyakorlat', 2, 39, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,117, 'Intelligens elosztott rendszerek labor', 3, 39, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,118, 'Rendszertervezes laboratorium 1 eloadas', 1, 40, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,119, 'Rendszertervezes laboratorium 1 gyakorlat', 2, 40, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,120, 'Rendszertervezes laboratorium 1 labor', 3, 40, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,121, 'Deklarativ programozas eloadas', 1, 41, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,122, 'Deklarativ programozas gyakorlat', 2, 41, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,123, 'Deklarativ programozas labor', 3, 41, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,124, 'Rendszertervezes laboratorium 2 eloadas', 1, 42, 1);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,125, 'Rendszertervezes laboratorium 2 gyakorlat', 2, 42, 5);");
    inserts.push_back("INSERT INTO classes (modified_timestamp,is_deleted,id,name,class_type_id,course_id,count) VALUES (current_timestamp,false,126, 'Rendszertervezes laboratorium 2 labor', 3, 42, 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,1, 'AUT eloadastarto 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,2, 'AUT gyakorlattarto 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,3, 'AUT gyakorlattarto 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,4, 'AUT gyakorlattarto 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,5, 'AUT gyakorlattarto 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,6, 'AUT gyakorlattarto 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,7, 'AUT labortarto 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,8, 'AUT labortarto 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,9, 'AUT labortarto 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,10, 'AUT labortarto 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,11, 'AUT labortarto 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,12, 'ETT eloadastarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,13, 'ETT gyakorlattarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,14, 'ETT gyakorlattarto 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,15, 'ETT gyakorlattarto 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,16, 'ETT gyakorlattarto 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,17, 'ETT gyakorlattarto 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,18, 'ETT labortarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,19, 'ETT labortarto 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,20, 'ETT labortarto 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,21, 'ETT labortarto 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,22, 'ETT labortarto 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,23, 'EET eloadastarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,24, 'EET gyakorlattarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,25, 'EET gyakorlattarto 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,26, 'EET gyakorlattarto 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,27, 'EET gyakorlattarto 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,28, 'EET gyakorlattarto 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,29, 'EET labortarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,30, 'EET labortarto 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,31, 'EET labortarto 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,32, 'EET labortarto 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,33, 'EET labortarto 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,34, 'HIT eloadastarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,35, 'HIT gyakorlattarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,36, 'HIT gyakorlattarto 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,37, 'HIT gyakorlattarto 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,38, 'HIT gyakorlattarto 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,39, 'HIT gyakorlattarto 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,40, 'HIT labortarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,41, 'HIT labortarto 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,42, 'HIT labortarto 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,43, 'HIT labortarto 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,44, 'HIT labortarto 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,45, 'IIT eloadastarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,46, 'IIT gyakorlattarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,47, 'IIT gyakorlattarto 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,48, 'IIT gyakorlattarto 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,49, 'IIT gyakorlattarto 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,50, 'IIT gyakorlattarto 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,51, 'IIT labortarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,52, 'IIT labortarto 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,53, 'IIT labortarto 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,54, 'IIT labortarto 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,55, 'IIT labortarto 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,56, 'MIT eloadastarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,57, 'MIT gyakorlattarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,58, 'MIT gyakorlattarto 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,59, 'MIT gyakorlattarto 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,60, 'MIT gyakorlattarto 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,61, 'MIT gyakorlattarto 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,62, 'MIT labortarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,63, 'MIT labortarto 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,64, 'MIT labortarto 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,65, 'MIT labortarto 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,66, 'MIT labortarto 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,67, 'SZIT eloadastarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,68, 'SZIT gyakorlattarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,69, 'SZIT gyakorlattarto 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,70, 'SZIT gyakorlattarto 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,71, 'SZIT gyakorlattarto 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,72, 'SZIT gyakorlattarto 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,73, 'SZIT labortarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,74, 'SZIT labortarto 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,75, 'SZIT labortarto 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,76, 'SZIT labortarto 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,77, 'SZIT labortarto 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,78, 'HVT eloadastarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,79, 'HVT gyakorlattarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,80, 'HVT gyakorlattarto 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,81, 'HVT gyakorlattarto 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,82, 'HVT gyakorlattarto 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,83, 'HVT gyakorlattarto 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,84, 'HVT labortarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,85, 'HVT labortarto 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,86, 'HVT labortarto 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,87, 'HVT labortarto 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,88, 'HVT labortarto 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,89, 'TMIT eloadastarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,90, 'TMIT gyakorlattarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,91, 'TMIT gyakorlattarto 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,92, 'TMIT gyakorlattarto 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,93, 'TMIT gyakorlattarto 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,94, 'TMIT gyakorlattarto 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,95, 'TMIT labortarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,96, 'TMIT labortarto 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,97, 'TMIT labortarto 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,98, 'TMIT labortarto 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,99, 'TMIT labortarto 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,100, 'VET eloadastarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,101, 'VET gyakorlattarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,102, 'VET gyakorlattarto 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,103, 'VET gyakorlattarto 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,104, 'VET gyakorlattarto 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,105, 'VET gyakorlattarto 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,106, 'VET labortarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,107, 'VET labortarto 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,108, 'VET labortarto 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,109, 'VET labortarto 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,110, 'VET labortarto 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,111, 'BTK eloadastarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,112, 'BTK gyakorlattarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,113, 'BTK gyakorlattarto 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,114, 'BTK gyakorlattarto 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,115, 'BTK gyakorlattarto 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,116, 'BTK gyakorlattarto 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,117, 'BTK labortarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,118, 'BTK labortarto 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,119, 'BTK labortarto 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,120, 'BTK labortarto 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,121, 'BTK labortarto 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,122, 'MAT eloadastarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,123, 'MAT gyakorlattarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,124, 'MAT gyakorlattarto 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,125, 'MAT gyakorlattarto 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,126, 'MAT gyakorlattarto 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,127, 'MAT gyakorlattarto 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,128, 'MAT labortarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,129, 'MAT labortarto 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,130, 'MAT labortarto 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,131, 'MAT labortarto 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,132, 'MAT labortarto 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,133, 'FIZ eloadastarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,134, 'FIZ gyakorlattarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,135, 'FIZ gyakorlattarto 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,136, 'FIZ gyakorlattarto 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,137, 'FIZ gyakorlattarto 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,138, 'FIZ gyakorlattarto 5', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,139, 'FIZ labortarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,140, 'FIZ labortarto 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,141, 'FIZ labortarto 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,142, 'FIZ labortarto 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,143, 'FIZ labortarto 5', 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,1, 28, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,2, 32, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,3, 38, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,4, 28, 2, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,5, 32, 2, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,6, 38, 2, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,7, 28, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,8, 32, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,9, 38, 2, 3);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,10, 28, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,11, 32, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,12, 38, 2, 4);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,13, 28, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,14, 32, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,15, 38, 2, 5);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,16, 28, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,17, 32, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,18, 38, 2, 6);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,19, 28, 3, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,20, 32, 3, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,21, 38, 3, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,22, 28, 3, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,23, 32, 3, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,24, 38, 3, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,25, 28, 3, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,26, 32, 3, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,27, 38, 3, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,28, 28, 3, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,29, 32, 3, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,30, 38, 3, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,31, 28, 3, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,32, 32, 3, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,33, 38, 3, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,34, 2, 1, 23);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,35, 29, 1, 23);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,36, 2, 2, 24);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,37, 29, 2, 24);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,38, 2, 2, 25);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,39, 29, 2, 25);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,40, 2, 2, 26);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,41, 29, 2, 26);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,42, 2, 2, 27);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,43, 29, 2, 27);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,44, 2, 2, 28);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,45, 29, 2, 28);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,46, 2, 3, 29);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,47, 29, 3, 29);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,48, 2, 3, 30);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,49, 29, 3, 30);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,50, 2, 3, 31);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,51, 29, 3, 31);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,52, 2, 3, 32);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,53, 29, 3, 32);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,54, 2, 3, 33);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,55, 29, 3, 33);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,56, 14, 1, 34);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,57, 17, 1, 34);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,58, 18, 1, 34);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,59, 37, 1, 34);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,60, 14, 2, 35);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,61, 17, 2, 35);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,62, 18, 2, 35);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,63, 37, 2, 35);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,64, 14, 2, 36);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,65, 17, 2, 36);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,66, 18, 2, 36);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,67, 37, 2, 36);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,68, 14, 2, 37);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,69, 17, 2, 37);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,70, 18, 2, 37);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,71, 37, 2, 37);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,72, 14, 2, 38);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,73, 17, 2, 38);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,74, 18, 2, 38);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,75, 37, 2, 38);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,76, 14, 2, 39);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,77, 17, 2, 39);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,78, 18, 2, 39);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,79, 37, 2, 39);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,80, 14, 3, 40);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,81, 17, 3, 40);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,82, 18, 3, 40);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,83, 37, 3, 40);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,84, 14, 3, 41);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,85, 17, 3, 41);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,86, 18, 3, 41);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,87, 37, 3, 41);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,88, 14, 3, 42);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,89, 17, 3, 42);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,90, 18, 3, 42);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,91, 37, 3, 42);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,92, 14, 3, 43);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,93, 17, 3, 43);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,94, 18, 3, 43);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,95, 37, 3, 43);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,96, 14, 3, 44);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,97, 17, 3, 44);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,98, 18, 3, 44);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,99, 37, 3, 44);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,100, 10, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,101, 15, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,102, 20, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,103, 26, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,104, 27, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,105, 35, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,106, 10, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,107, 15, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,108, 20, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,109, 26, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,110, 27, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,111, 35, 2, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,112, 10, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,113, 15, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,114, 20, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,115, 26, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,116, 27, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,117, 35, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,118, 10, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,119, 15, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,120, 20, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,121, 26, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,122, 27, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,123, 35, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,124, 10, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,125, 15, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,126, 20, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,127, 26, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,128, 27, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,129, 35, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,130, 10, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,131, 15, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,132, 20, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,133, 26, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,134, 27, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,135, 35, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,136, 10, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,137, 15, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,138, 20, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,139, 26, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,140, 27, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,141, 35, 3, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,142, 10, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,143, 15, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,144, 20, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,145, 26, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,146, 27, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,147, 35, 3, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,148, 10, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,149, 15, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,150, 20, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,151, 26, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,152, 27, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,153, 35, 3, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,154, 10, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,155, 15, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,156, 20, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,157, 26, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,158, 27, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,159, 35, 3, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,160, 10, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,161, 15, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,162, 20, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,163, 26, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,164, 27, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,165, 35, 3, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,166, 6, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,167, 13, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,168, 25, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,169, 30, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,170, 34, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,171, 39, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,172, 40, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,173, 42, 1, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,174, 6, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,175, 13, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,176, 25, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,177, 30, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,178, 34, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,179, 39, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,180, 40, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,181, 42, 2, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,182, 6, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,183, 13, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,184, 25, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,185, 30, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,186, 34, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,187, 39, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,188, 40, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,189, 42, 2, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,190, 6, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,191, 13, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,192, 25, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,193, 30, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,194, 34, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,195, 39, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,196, 40, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,197, 42, 2, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,198, 6, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,199, 13, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,200, 25, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,201, 30, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,202, 34, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,203, 39, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,204, 40, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,205, 42, 2, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,206, 6, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,207, 13, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,208, 25, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,209, 30, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,210, 34, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,211, 39, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,212, 40, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,213, 42, 2, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,214, 6, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,215, 13, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,216, 25, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,217, 30, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,218, 34, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,219, 39, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,220, 40, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,221, 42, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,222, 6, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,223, 13, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,224, 25, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,225, 30, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,226, 34, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,227, 39, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,228, 40, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,229, 42, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,230, 6, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,231, 13, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,232, 25, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,233, 30, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,234, 34, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,235, 39, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,236, 40, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,237, 42, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,238, 6, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,239, 13, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,240, 25, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,241, 30, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,242, 34, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,243, 39, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,244, 40, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,245, 42, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,246, 6, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,247, 13, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,248, 25, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,249, 30, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,250, 34, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,251, 39, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,252, 40, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,253, 42, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,254, 3, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,255, 11, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,256, 21, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,257, 22, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,258, 41, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,259, 3, 2, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,260, 11, 2, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,261, 21, 2, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,262, 22, 2, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,263, 41, 2, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,264, 3, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,265, 11, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,266, 21, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,267, 22, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,268, 41, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,269, 3, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,270, 11, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,271, 21, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,272, 22, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,273, 41, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,274, 3, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,275, 11, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,276, 21, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,277, 22, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,278, 41, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,279, 3, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,280, 11, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,281, 21, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,282, 22, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,283, 41, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,284, 3, 3, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,285, 11, 3, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,286, 21, 3, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,287, 22, 3, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,288, 41, 3, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,289, 3, 3, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,290, 11, 3, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,291, 21, 3, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,292, 22, 3, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,293, 41, 3, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,294, 3, 3, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,295, 11, 3, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,296, 21, 3, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,297, 22, 3, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,298, 41, 3, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,299, 3, 3, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,300, 11, 3, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,301, 21, 3, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,302, 22, 3, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,303, 41, 3, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,304, 3, 3, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,305, 11, 3, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,306, 21, 3, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,307, 22, 3, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,308, 41, 3, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,309, 19, 1, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,310, 19, 2, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,311, 19, 2, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,312, 19, 2, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,313, 19, 2, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,314, 19, 2, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,315, 19, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,316, 19, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,317, 19, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,318, 19, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,319, 19, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,320, 16, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,321, 23, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,322, 36, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,323, 16, 2, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,324, 23, 2, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,325, 36, 2, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,326, 16, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,327, 23, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,328, 36, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,329, 16, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,330, 23, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,331, 36, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,332, 16, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,333, 23, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,334, 36, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,335, 16, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,336, 23, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,337, 36, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,338, 16, 3, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,339, 23, 3, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,340, 36, 3, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,341, 16, 3, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,342, 23, 3, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,343, 36, 3, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,344, 16, 3, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,345, 23, 3, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,346, 36, 3, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,347, 16, 3, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,348, 23, 3, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,349, 36, 3, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,350, 16, 3, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,351, 23, 3, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,352, 36, 3, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,353, 8, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,354, 24, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,355, 31, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,356, 33, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,357, 8, 2, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,358, 24, 2, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,359, 31, 2, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,360, 33, 2, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,361, 8, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,362, 24, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,363, 31, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,364, 33, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,365, 8, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,366, 24, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,367, 31, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,368, 33, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,369, 8, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,370, 24, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,371, 31, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,372, 33, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,373, 8, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,374, 24, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,375, 31, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,376, 33, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,377, 8, 3, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,378, 24, 3, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,379, 31, 3, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,380, 33, 3, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,381, 8, 3, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,382, 24, 3, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,383, 31, 3, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,384, 33, 3, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,385, 8, 3, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,386, 24, 3, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,387, 31, 3, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,388, 33, 3, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,389, 8, 3, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,390, 24, 3, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,391, 31, 3, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,392, 33, 3, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,393, 8, 3, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,394, 24, 3, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,395, 31, 3, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,396, 33, 3, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,397, 1, 1, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,398, 5, 1, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,399, 9, 1, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,400, 1, 2, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,401, 5, 2, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,402, 9, 2, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,403, 1, 2, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,404, 5, 2, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,405, 9, 2, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,406, 1, 2, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,407, 5, 2, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,408, 9, 2, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,409, 1, 2, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,410, 5, 2, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,411, 9, 2, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,412, 1, 2, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,413, 5, 2, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,414, 9, 2, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,415, 1, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,416, 5, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,417, 9, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,418, 1, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,419, 5, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,420, 9, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,421, 1, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,422, 5, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,423, 9, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,424, 1, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,425, 5, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,426, 9, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,427, 1, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,428, 5, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,429, 9, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,430, 4, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,431, 7, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,432, 12, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,433, 4, 2, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,434, 7, 2, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,435, 12, 2, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,436, 4, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,437, 7, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,438, 12, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,439, 4, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,440, 7, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,441, 12, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,442, 4, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,443, 7, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,444, 12, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,445, 4, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,446, 7, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,447, 12, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,448, 4, 3, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,449, 7, 3, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,450, 12, 3, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,451, 4, 3, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,452, 7, 3, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,453, 12, 3, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,454, 4, 3, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,455, 7, 3, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,456, 12, 3, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,457, 4, 3, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,458, 7, 3, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,459, 12, 3, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,460, 4, 3, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,461, 7, 3, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,462, 12, 3, 143);");
    try {

        pqxx::work w(_db);

        for(auto insert : inserts) {

            w.exec(insert);
        }

        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

void DatabasePartial::destroy() {

    try {

        pqxx::work w(_db);
        w.exec("DROP OWNED BY " + _user + ";");
        w.commit();

    } catch (std::exception& e) {

        std::cerr << e.what();
    }
}

