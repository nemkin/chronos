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
                i[4].as<int>(), // location_id
                i[5].as<int>() // class_type_id
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

bool DatabasePartial::test() {

    if(_db.is_open()) {

        std::cout << "Connection successful!" << std::endl;

    } else {

        std::cout << "Connection failed." << std::endl;
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
        "CREATE TABLE rooms ( "
            "id SERIAL PRIMARY KEY NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN NOT NULL, "
            "name TEXT NOT NULL, "
            "location_id INTEGER REFERENCES locations(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL);"
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
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,1, 'CHC14', 2, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,2, 'E1A', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,3, 'E1B', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,4, 'E1C', 3, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,5, 'E305c', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,6, 'E306ab', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,7, 'E306cd', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,8, 'E401', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,9, 'E402', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,10, 'E403', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,11, 'E404', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,12, 'E405', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,13, 'E406', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,14, 'E407', 3, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,15, 'F29', 11, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,16, 'H406', 4, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,17, 'IB026', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,18, 'IB027', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,19, 'IB028', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,20, 'IB134', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,21, 'IB138', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,22, 'IB139', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,23, 'IB140', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,24, 'IB141', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,25, 'IB142', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,26, 'IB144', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,27, 'IB145', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,28, 'IB146', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,29, 'IB147', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,30, 'IB310', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,31, 'IB413', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,32, 'IE007', 5, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,33, 'IE217-1', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,34, 'IE218', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,35, 'IE219', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,36, 'IE220', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,37, 'IE221', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,38, 'IE223', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,39, 'IE224', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,40, 'IE226', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,41, 'IE320', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,42, 'IE321', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,43, 'IL105', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,44, 'IL407', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,45, 'IL408', 5, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,46, 'K134', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,47, 'K174', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,48, 'KF51 (AUD.MAX)', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,49, 'KF81', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,50, 'KF87', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,51, 'KF88', 6, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,52, 'QA240', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,53, 'QAF14', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,54, 'QB105', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,55, 'QB-310', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,56, 'QB311', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,57, 'QB331', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,58, 'QBF08', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,59, 'QBF10', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,60, 'QBF11', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,61, 'QBF12', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,62, 'QBF13', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,63, 'QBP', 7, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,64, 'Q-I', 7, 1);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,65, 'R4A', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,66, 'R4B', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,67, 'R4C', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,68, 'R4I', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,69, 'R4J', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,70, 'R4K', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,71, 'R4L', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,72, 'R4M', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,73, 'R4N', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,74, 'R4O', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,75, 'R4P', 8, 3);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,76, 'R504', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,77, 'R505', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,78, 'R506', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,79, 'R507', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,80, 'R508', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,81, 'R511', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,82, 'R515', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,83, 'R516', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,84, 'R517', 8, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,85, 'T604', 9, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,86, 'V1109', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,87, 'V1501', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,88, 'V1502', 10, 2);");
    inserts.push_back("INSERT INTO rooms (modified_timestamp,is_deleted,id,name,location_id,class_type_id) VALUES (current_timestamp,false,89, 'V1526', 10, 2);");
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
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,2, 'AUT eloadastarto 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,3, 'AUT gyakorlattarto 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,4, 'AUT gyakorlattarto 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,5, 'AUT gyakorlattarto 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,6, 'AUT gyakorlattarto 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,7, 'AUT gyakorlattarto 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,8, 'AUT gyakorlattarto 6', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,9, 'AUT gyakorlattarto 7', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,10, 'AUT gyakorlattarto 8', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,11, 'AUT gyakorlattarto 9', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,12, 'AUT gyakorlattarto 10', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,13, 'AUT labortarto 1', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,14, 'AUT labortarto 2', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,15, 'AUT labortarto 3', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,16, 'AUT labortarto 4', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,17, 'AUT labortarto 5', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,18, 'AUT labortarto 6', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,19, 'AUT labortarto 7', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,20, 'AUT labortarto 8', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,21, 'AUT labortarto 9', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,22, 'AUT labortarto 10', 1);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,23, 'ETT eloadastarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,24, 'ETT eloadastarto 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,25, 'ETT gyakorlattarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,26, 'ETT gyakorlattarto 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,27, 'ETT gyakorlattarto 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,28, 'ETT gyakorlattarto 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,29, 'ETT gyakorlattarto 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,30, 'ETT gyakorlattarto 6', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,31, 'ETT gyakorlattarto 7', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,32, 'ETT gyakorlattarto 8', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,33, 'ETT gyakorlattarto 9', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,34, 'ETT gyakorlattarto 10', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,35, 'ETT labortarto 1', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,36, 'ETT labortarto 2', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,37, 'ETT labortarto 3', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,38, 'ETT labortarto 4', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,39, 'ETT labortarto 5', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,40, 'ETT labortarto 6', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,41, 'ETT labortarto 7', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,42, 'ETT labortarto 8', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,43, 'ETT labortarto 9', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,44, 'ETT labortarto 10', 2);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,45, 'EET eloadastarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,46, 'EET eloadastarto 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,47, 'EET gyakorlattarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,48, 'EET gyakorlattarto 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,49, 'EET gyakorlattarto 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,50, 'EET gyakorlattarto 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,51, 'EET gyakorlattarto 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,52, 'EET gyakorlattarto 6', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,53, 'EET gyakorlattarto 7', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,54, 'EET gyakorlattarto 8', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,55, 'EET gyakorlattarto 9', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,56, 'EET gyakorlattarto 10', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,57, 'EET labortarto 1', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,58, 'EET labortarto 2', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,59, 'EET labortarto 3', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,60, 'EET labortarto 4', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,61, 'EET labortarto 5', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,62, 'EET labortarto 6', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,63, 'EET labortarto 7', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,64, 'EET labortarto 8', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,65, 'EET labortarto 9', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,66, 'EET labortarto 10', 3);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,67, 'HIT eloadastarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,68, 'HIT eloadastarto 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,69, 'HIT gyakorlattarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,70, 'HIT gyakorlattarto 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,71, 'HIT gyakorlattarto 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,72, 'HIT gyakorlattarto 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,73, 'HIT gyakorlattarto 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,74, 'HIT gyakorlattarto 6', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,75, 'HIT gyakorlattarto 7', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,76, 'HIT gyakorlattarto 8', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,77, 'HIT gyakorlattarto 9', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,78, 'HIT gyakorlattarto 10', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,79, 'HIT labortarto 1', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,80, 'HIT labortarto 2', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,81, 'HIT labortarto 3', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,82, 'HIT labortarto 4', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,83, 'HIT labortarto 5', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,84, 'HIT labortarto 6', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,85, 'HIT labortarto 7', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,86, 'HIT labortarto 8', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,87, 'HIT labortarto 9', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,88, 'HIT labortarto 10', 4);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,89, 'IIT eloadastarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,90, 'IIT eloadastarto 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,91, 'IIT gyakorlattarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,92, 'IIT gyakorlattarto 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,93, 'IIT gyakorlattarto 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,94, 'IIT gyakorlattarto 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,95, 'IIT gyakorlattarto 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,96, 'IIT gyakorlattarto 6', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,97, 'IIT gyakorlattarto 7', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,98, 'IIT gyakorlattarto 8', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,99, 'IIT gyakorlattarto 9', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,100, 'IIT gyakorlattarto 10', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,101, 'IIT labortarto 1', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,102, 'IIT labortarto 2', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,103, 'IIT labortarto 3', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,104, 'IIT labortarto 4', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,105, 'IIT labortarto 5', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,106, 'IIT labortarto 6', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,107, 'IIT labortarto 7', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,108, 'IIT labortarto 8', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,109, 'IIT labortarto 9', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,110, 'IIT labortarto 10', 5);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,111, 'MIT eloadastarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,112, 'MIT eloadastarto 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,113, 'MIT gyakorlattarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,114, 'MIT gyakorlattarto 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,115, 'MIT gyakorlattarto 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,116, 'MIT gyakorlattarto 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,117, 'MIT gyakorlattarto 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,118, 'MIT gyakorlattarto 6', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,119, 'MIT gyakorlattarto 7', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,120, 'MIT gyakorlattarto 8', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,121, 'MIT gyakorlattarto 9', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,122, 'MIT gyakorlattarto 10', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,123, 'MIT labortarto 1', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,124, 'MIT labortarto 2', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,125, 'MIT labortarto 3', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,126, 'MIT labortarto 4', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,127, 'MIT labortarto 5', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,128, 'MIT labortarto 6', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,129, 'MIT labortarto 7', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,130, 'MIT labortarto 8', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,131, 'MIT labortarto 9', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,132, 'MIT labortarto 10', 6);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,133, 'SZIT eloadastarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,134, 'SZIT eloadastarto 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,135, 'SZIT gyakorlattarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,136, 'SZIT gyakorlattarto 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,137, 'SZIT gyakorlattarto 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,138, 'SZIT gyakorlattarto 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,139, 'SZIT gyakorlattarto 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,140, 'SZIT gyakorlattarto 6', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,141, 'SZIT gyakorlattarto 7', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,142, 'SZIT gyakorlattarto 8', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,143, 'SZIT gyakorlattarto 9', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,144, 'SZIT gyakorlattarto 10', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,145, 'SZIT labortarto 1', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,146, 'SZIT labortarto 2', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,147, 'SZIT labortarto 3', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,148, 'SZIT labortarto 4', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,149, 'SZIT labortarto 5', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,150, 'SZIT labortarto 6', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,151, 'SZIT labortarto 7', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,152, 'SZIT labortarto 8', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,153, 'SZIT labortarto 9', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,154, 'SZIT labortarto 10', 7);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,155, 'HVT eloadastarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,156, 'HVT eloadastarto 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,157, 'HVT gyakorlattarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,158, 'HVT gyakorlattarto 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,159, 'HVT gyakorlattarto 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,160, 'HVT gyakorlattarto 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,161, 'HVT gyakorlattarto 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,162, 'HVT gyakorlattarto 6', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,163, 'HVT gyakorlattarto 7', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,164, 'HVT gyakorlattarto 8', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,165, 'HVT gyakorlattarto 9', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,166, 'HVT gyakorlattarto 10', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,167, 'HVT labortarto 1', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,168, 'HVT labortarto 2', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,169, 'HVT labortarto 3', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,170, 'HVT labortarto 4', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,171, 'HVT labortarto 5', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,172, 'HVT labortarto 6', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,173, 'HVT labortarto 7', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,174, 'HVT labortarto 8', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,175, 'HVT labortarto 9', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,176, 'HVT labortarto 10', 8);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,177, 'TMIT eloadastarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,178, 'TMIT eloadastarto 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,179, 'TMIT gyakorlattarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,180, 'TMIT gyakorlattarto 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,181, 'TMIT gyakorlattarto 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,182, 'TMIT gyakorlattarto 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,183, 'TMIT gyakorlattarto 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,184, 'TMIT gyakorlattarto 6', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,185, 'TMIT gyakorlattarto 7', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,186, 'TMIT gyakorlattarto 8', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,187, 'TMIT gyakorlattarto 9', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,188, 'TMIT gyakorlattarto 10', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,189, 'TMIT labortarto 1', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,190, 'TMIT labortarto 2', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,191, 'TMIT labortarto 3', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,192, 'TMIT labortarto 4', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,193, 'TMIT labortarto 5', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,194, 'TMIT labortarto 6', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,195, 'TMIT labortarto 7', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,196, 'TMIT labortarto 8', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,197, 'TMIT labortarto 9', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,198, 'TMIT labortarto 10', 9);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,199, 'VET eloadastarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,200, 'VET eloadastarto 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,201, 'VET gyakorlattarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,202, 'VET gyakorlattarto 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,203, 'VET gyakorlattarto 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,204, 'VET gyakorlattarto 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,205, 'VET gyakorlattarto 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,206, 'VET gyakorlattarto 6', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,207, 'VET gyakorlattarto 7', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,208, 'VET gyakorlattarto 8', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,209, 'VET gyakorlattarto 9', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,210, 'VET gyakorlattarto 10', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,211, 'VET labortarto 1', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,212, 'VET labortarto 2', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,213, 'VET labortarto 3', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,214, 'VET labortarto 4', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,215, 'VET labortarto 5', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,216, 'VET labortarto 6', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,217, 'VET labortarto 7', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,218, 'VET labortarto 8', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,219, 'VET labortarto 9', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,220, 'VET labortarto 10', 10);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,221, 'BTK eloadastarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,222, 'BTK eloadastarto 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,223, 'BTK gyakorlattarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,224, 'BTK gyakorlattarto 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,225, 'BTK gyakorlattarto 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,226, 'BTK gyakorlattarto 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,227, 'BTK gyakorlattarto 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,228, 'BTK gyakorlattarto 6', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,229, 'BTK gyakorlattarto 7', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,230, 'BTK gyakorlattarto 8', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,231, 'BTK gyakorlattarto 9', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,232, 'BTK gyakorlattarto 10', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,233, 'BTK labortarto 1', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,234, 'BTK labortarto 2', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,235, 'BTK labortarto 3', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,236, 'BTK labortarto 4', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,237, 'BTK labortarto 5', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,238, 'BTK labortarto 6', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,239, 'BTK labortarto 7', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,240, 'BTK labortarto 8', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,241, 'BTK labortarto 9', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,242, 'BTK labortarto 10', 11);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,243, 'MAT eloadastarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,244, 'MAT eloadastarto 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,245, 'MAT gyakorlattarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,246, 'MAT gyakorlattarto 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,247, 'MAT gyakorlattarto 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,248, 'MAT gyakorlattarto 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,249, 'MAT gyakorlattarto 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,250, 'MAT gyakorlattarto 6', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,251, 'MAT gyakorlattarto 7', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,252, 'MAT gyakorlattarto 8', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,253, 'MAT gyakorlattarto 9', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,254, 'MAT gyakorlattarto 10', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,255, 'MAT labortarto 1', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,256, 'MAT labortarto 2', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,257, 'MAT labortarto 3', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,258, 'MAT labortarto 4', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,259, 'MAT labortarto 5', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,260, 'MAT labortarto 6', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,261, 'MAT labortarto 7', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,262, 'MAT labortarto 8', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,263, 'MAT labortarto 9', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,264, 'MAT labortarto 10', 12);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,265, 'FIZ eloadastarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,266, 'FIZ eloadastarto 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,267, 'FIZ gyakorlattarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,268, 'FIZ gyakorlattarto 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,269, 'FIZ gyakorlattarto 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,270, 'FIZ gyakorlattarto 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,271, 'FIZ gyakorlattarto 5', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,272, 'FIZ gyakorlattarto 6', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,273, 'FIZ gyakorlattarto 7', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,274, 'FIZ gyakorlattarto 8', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,275, 'FIZ gyakorlattarto 9', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,276, 'FIZ gyakorlattarto 10', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,277, 'FIZ labortarto 1', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,278, 'FIZ labortarto 2', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,279, 'FIZ labortarto 3', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,280, 'FIZ labortarto 4', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,281, 'FIZ labortarto 5', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,282, 'FIZ labortarto 6', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,283, 'FIZ labortarto 7', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,284, 'FIZ labortarto 8', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,285, 'FIZ labortarto 9', 13);");
    inserts.push_back("INSERT INTO faculty_members (modified_timestamp,is_deleted,id,name,department_id) VALUES (current_timestamp,false,286, 'FIZ labortarto 10', 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,1, 28, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,2, 32, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,3, 38, 1, 1);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,4, 28, 1, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,5, 32, 1, 2);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,6, 38, 1, 2);");
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
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,19, 28, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,20, 32, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,21, 38, 2, 7);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,22, 28, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,23, 32, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,24, 38, 2, 8);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,25, 28, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,26, 32, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,27, 38, 2, 9);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,28, 28, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,29, 32, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,30, 38, 2, 10);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,31, 28, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,32, 32, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,33, 38, 2, 11);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,34, 28, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,35, 32, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,36, 38, 2, 12);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,37, 28, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,38, 32, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,39, 38, 3, 13);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,40, 28, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,41, 32, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,42, 38, 3, 14);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,43, 28, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,44, 32, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,45, 38, 3, 15);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,46, 28, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,47, 32, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,48, 38, 3, 16);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,49, 28, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,50, 32, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,51, 38, 3, 17);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,52, 28, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,53, 32, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,54, 38, 3, 18);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,55, 28, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,56, 32, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,57, 38, 3, 19);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,58, 28, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,59, 32, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,60, 38, 3, 20);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,61, 28, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,62, 32, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,63, 38, 3, 21);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,64, 28, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,65, 32, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,66, 38, 3, 22);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,67, 2, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,68, 29, 1, 45);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,69, 2, 1, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,70, 29, 1, 46);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,71, 2, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,72, 29, 2, 47);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,73, 2, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,74, 29, 2, 48);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,75, 2, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,76, 29, 2, 49);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,77, 2, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,78, 29, 2, 50);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,79, 2, 2, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,80, 29, 2, 51);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,81, 2, 2, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,82, 29, 2, 52);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,83, 2, 2, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,84, 29, 2, 53);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,85, 2, 2, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,86, 29, 2, 54);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,87, 2, 2, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,88, 29, 2, 55);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,89, 2, 2, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,90, 29, 2, 56);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,91, 2, 3, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,92, 29, 3, 57);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,93, 2, 3, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,94, 29, 3, 58);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,95, 2, 3, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,96, 29, 3, 59);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,97, 2, 3, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,98, 29, 3, 60);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,99, 2, 3, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,100, 29, 3, 61);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,101, 2, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,102, 29, 3, 62);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,103, 2, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,104, 29, 3, 63);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,105, 2, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,106, 29, 3, 64);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,107, 2, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,108, 29, 3, 65);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,109, 2, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,110, 29, 3, 66);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,111, 14, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,112, 17, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,113, 18, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,114, 37, 1, 67);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,115, 14, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,116, 17, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,117, 18, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,118, 37, 1, 68);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,119, 14, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,120, 17, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,121, 18, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,122, 37, 2, 69);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,123, 14, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,124, 17, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,125, 18, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,126, 37, 2, 70);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,127, 14, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,128, 17, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,129, 18, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,130, 37, 2, 71);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,131, 14, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,132, 17, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,133, 18, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,134, 37, 2, 72);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,135, 14, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,136, 17, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,137, 18, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,138, 37, 2, 73);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,139, 14, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,140, 17, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,141, 18, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,142, 37, 2, 74);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,143, 14, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,144, 17, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,145, 18, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,146, 37, 2, 75);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,147, 14, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,148, 17, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,149, 18, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,150, 37, 2, 76);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,151, 14, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,152, 17, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,153, 18, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,154, 37, 2, 77);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,155, 14, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,156, 17, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,157, 18, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,158, 37, 2, 78);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,159, 14, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,160, 17, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,161, 18, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,162, 37, 3, 79);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,163, 14, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,164, 17, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,165, 18, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,166, 37, 3, 80);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,167, 14, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,168, 17, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,169, 18, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,170, 37, 3, 81);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,171, 14, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,172, 17, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,173, 18, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,174, 37, 3, 82);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,175, 14, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,176, 17, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,177, 18, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,178, 37, 3, 83);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,179, 14, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,180, 17, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,181, 18, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,182, 37, 3, 84);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,183, 14, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,184, 17, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,185, 18, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,186, 37, 3, 85);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,187, 14, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,188, 17, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,189, 18, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,190, 37, 3, 86);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,191, 14, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,192, 17, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,193, 18, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,194, 37, 3, 87);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,195, 14, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,196, 17, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,197, 18, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,198, 37, 3, 88);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,199, 10, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,200, 15, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,201, 20, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,202, 26, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,203, 27, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,204, 35, 1, 89);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,205, 10, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,206, 15, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,207, 20, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,208, 26, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,209, 27, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,210, 35, 1, 90);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,211, 10, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,212, 15, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,213, 20, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,214, 26, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,215, 27, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,216, 35, 2, 91);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,217, 10, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,218, 15, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,219, 20, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,220, 26, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,221, 27, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,222, 35, 2, 92);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,223, 10, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,224, 15, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,225, 20, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,226, 26, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,227, 27, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,228, 35, 2, 93);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,229, 10, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,230, 15, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,231, 20, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,232, 26, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,233, 27, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,234, 35, 2, 94);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,235, 10, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,236, 15, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,237, 20, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,238, 26, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,239, 27, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,240, 35, 2, 95);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,241, 10, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,242, 15, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,243, 20, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,244, 26, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,245, 27, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,246, 35, 2, 96);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,247, 10, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,248, 15, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,249, 20, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,250, 26, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,251, 27, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,252, 35, 2, 97);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,253, 10, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,254, 15, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,255, 20, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,256, 26, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,257, 27, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,258, 35, 2, 98);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,259, 10, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,260, 15, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,261, 20, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,262, 26, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,263, 27, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,264, 35, 2, 99);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,265, 10, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,266, 15, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,267, 20, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,268, 26, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,269, 27, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,270, 35, 2, 100);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,271, 10, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,272, 15, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,273, 20, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,274, 26, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,275, 27, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,276, 35, 3, 101);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,277, 10, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,278, 15, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,279, 20, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,280, 26, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,281, 27, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,282, 35, 3, 102);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,283, 10, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,284, 15, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,285, 20, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,286, 26, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,287, 27, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,288, 35, 3, 103);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,289, 10, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,290, 15, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,291, 20, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,292, 26, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,293, 27, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,294, 35, 3, 104);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,295, 10, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,296, 15, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,297, 20, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,298, 26, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,299, 27, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,300, 35, 3, 105);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,301, 10, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,302, 15, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,303, 20, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,304, 26, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,305, 27, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,306, 35, 3, 106);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,307, 10, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,308, 15, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,309, 20, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,310, 26, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,311, 27, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,312, 35, 3, 107);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,313, 10, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,314, 15, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,315, 20, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,316, 26, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,317, 27, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,318, 35, 3, 108);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,319, 10, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,320, 15, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,321, 20, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,322, 26, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,323, 27, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,324, 35, 3, 109);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,325, 10, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,326, 15, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,327, 20, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,328, 26, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,329, 27, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,330, 35, 3, 110);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,331, 6, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,332, 13, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,333, 25, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,334, 30, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,335, 34, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,336, 39, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,337, 40, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,338, 42, 1, 111);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,339, 6, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,340, 13, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,341, 25, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,342, 30, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,343, 34, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,344, 39, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,345, 40, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,346, 42, 1, 112);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,347, 6, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,348, 13, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,349, 25, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,350, 30, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,351, 34, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,352, 39, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,353, 40, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,354, 42, 2, 113);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,355, 6, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,356, 13, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,357, 25, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,358, 30, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,359, 34, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,360, 39, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,361, 40, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,362, 42, 2, 114);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,363, 6, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,364, 13, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,365, 25, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,366, 30, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,367, 34, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,368, 39, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,369, 40, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,370, 42, 2, 115);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,371, 6, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,372, 13, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,373, 25, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,374, 30, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,375, 34, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,376, 39, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,377, 40, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,378, 42, 2, 116);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,379, 6, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,380, 13, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,381, 25, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,382, 30, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,383, 34, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,384, 39, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,385, 40, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,386, 42, 2, 117);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,387, 6, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,388, 13, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,389, 25, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,390, 30, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,391, 34, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,392, 39, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,393, 40, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,394, 42, 2, 118);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,395, 6, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,396, 13, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,397, 25, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,398, 30, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,399, 34, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,400, 39, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,401, 40, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,402, 42, 2, 119);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,403, 6, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,404, 13, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,405, 25, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,406, 30, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,407, 34, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,408, 39, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,409, 40, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,410, 42, 2, 120);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,411, 6, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,412, 13, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,413, 25, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,414, 30, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,415, 34, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,416, 39, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,417, 40, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,418, 42, 2, 121);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,419, 6, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,420, 13, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,421, 25, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,422, 30, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,423, 34, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,424, 39, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,425, 40, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,426, 42, 2, 122);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,427, 6, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,428, 13, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,429, 25, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,430, 30, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,431, 34, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,432, 39, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,433, 40, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,434, 42, 3, 123);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,435, 6, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,436, 13, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,437, 25, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,438, 30, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,439, 34, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,440, 39, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,441, 40, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,442, 42, 3, 124);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,443, 6, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,444, 13, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,445, 25, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,446, 30, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,447, 34, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,448, 39, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,449, 40, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,450, 42, 3, 125);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,451, 6, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,452, 13, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,453, 25, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,454, 30, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,455, 34, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,456, 39, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,457, 40, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,458, 42, 3, 126);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,459, 6, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,460, 13, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,461, 25, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,462, 30, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,463, 34, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,464, 39, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,465, 40, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,466, 42, 3, 127);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,467, 6, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,468, 13, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,469, 25, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,470, 30, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,471, 34, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,472, 39, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,473, 40, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,474, 42, 3, 128);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,475, 6, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,476, 13, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,477, 25, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,478, 30, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,479, 34, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,480, 39, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,481, 40, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,482, 42, 3, 129);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,483, 6, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,484, 13, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,485, 25, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,486, 30, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,487, 34, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,488, 39, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,489, 40, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,490, 42, 3, 130);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,491, 6, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,492, 13, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,493, 25, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,494, 30, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,495, 34, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,496, 39, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,497, 40, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,498, 42, 3, 131);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,499, 6, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,500, 13, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,501, 25, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,502, 30, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,503, 34, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,504, 39, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,505, 40, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,506, 42, 3, 132);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,507, 3, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,508, 11, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,509, 21, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,510, 22, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,511, 41, 1, 133);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,512, 3, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,513, 11, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,514, 21, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,515, 22, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,516, 41, 1, 134);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,517, 3, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,518, 11, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,519, 21, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,520, 22, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,521, 41, 2, 135);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,522, 3, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,523, 11, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,524, 21, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,525, 22, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,526, 41, 2, 136);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,527, 3, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,528, 11, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,529, 21, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,530, 22, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,531, 41, 2, 137);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,532, 3, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,533, 11, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,534, 21, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,535, 22, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,536, 41, 2, 138);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,537, 3, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,538, 11, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,539, 21, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,540, 22, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,541, 41, 2, 139);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,542, 3, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,543, 11, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,544, 21, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,545, 22, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,546, 41, 2, 140);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,547, 3, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,548, 11, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,549, 21, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,550, 22, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,551, 41, 2, 141);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,552, 3, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,553, 11, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,554, 21, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,555, 22, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,556, 41, 2, 142);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,557, 3, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,558, 11, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,559, 21, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,560, 22, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,561, 41, 2, 143);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,562, 3, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,563, 11, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,564, 21, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,565, 22, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,566, 41, 2, 144);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,567, 3, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,568, 11, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,569, 21, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,570, 22, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,571, 41, 3, 145);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,572, 3, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,573, 11, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,574, 21, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,575, 22, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,576, 41, 3, 146);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,577, 3, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,578, 11, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,579, 21, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,580, 22, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,581, 41, 3, 147);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,582, 3, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,583, 11, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,584, 21, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,585, 22, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,586, 41, 3, 148);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,587, 3, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,588, 11, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,589, 21, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,590, 22, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,591, 41, 3, 149);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,592, 3, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,593, 11, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,594, 21, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,595, 22, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,596, 41, 3, 150);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,597, 3, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,598, 11, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,599, 21, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,600, 22, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,601, 41, 3, 151);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,602, 3, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,603, 11, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,604, 21, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,605, 22, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,606, 41, 3, 152);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,607, 3, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,608, 11, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,609, 21, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,610, 22, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,611, 41, 3, 153);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,612, 3, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,613, 11, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,614, 21, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,615, 22, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,616, 41, 3, 154);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,617, 19, 1, 155);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,618, 19, 1, 156);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,619, 19, 2, 157);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,620, 19, 2, 158);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,621, 19, 2, 159);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,622, 19, 2, 160);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,623, 19, 2, 161);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,624, 19, 2, 162);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,625, 19, 2, 163);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,626, 19, 2, 164);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,627, 19, 2, 165);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,628, 19, 2, 166);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,629, 19, 3, 167);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,630, 19, 3, 168);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,631, 19, 3, 169);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,632, 19, 3, 170);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,633, 19, 3, 171);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,634, 19, 3, 172);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,635, 19, 3, 173);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,636, 19, 3, 174);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,637, 19, 3, 175);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,638, 19, 3, 176);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,639, 16, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,640, 23, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,641, 36, 1, 177);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,642, 16, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,643, 23, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,644, 36, 1, 178);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,645, 16, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,646, 23, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,647, 36, 2, 179);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,648, 16, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,649, 23, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,650, 36, 2, 180);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,651, 16, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,652, 23, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,653, 36, 2, 181);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,654, 16, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,655, 23, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,656, 36, 2, 182);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,657, 16, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,658, 23, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,659, 36, 2, 183);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,660, 16, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,661, 23, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,662, 36, 2, 184);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,663, 16, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,664, 23, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,665, 36, 2, 185);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,666, 16, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,667, 23, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,668, 36, 2, 186);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,669, 16, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,670, 23, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,671, 36, 2, 187);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,672, 16, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,673, 23, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,674, 36, 2, 188);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,675, 16, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,676, 23, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,677, 36, 3, 189);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,678, 16, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,679, 23, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,680, 36, 3, 190);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,681, 16, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,682, 23, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,683, 36, 3, 191);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,684, 16, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,685, 23, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,686, 36, 3, 192);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,687, 16, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,688, 23, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,689, 36, 3, 193);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,690, 16, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,691, 23, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,692, 36, 3, 194);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,693, 16, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,694, 23, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,695, 36, 3, 195);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,696, 16, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,697, 23, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,698, 36, 3, 196);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,699, 16, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,700, 23, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,701, 36, 3, 197);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,702, 16, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,703, 23, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,704, 36, 3, 198);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,705, 8, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,706, 24, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,707, 31, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,708, 33, 1, 221);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,709, 8, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,710, 24, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,711, 31, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,712, 33, 1, 222);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,713, 8, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,714, 24, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,715, 31, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,716, 33, 2, 223);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,717, 8, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,718, 24, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,719, 31, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,720, 33, 2, 224);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,721, 8, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,722, 24, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,723, 31, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,724, 33, 2, 225);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,725, 8, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,726, 24, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,727, 31, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,728, 33, 2, 226);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,729, 8, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,730, 24, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,731, 31, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,732, 33, 2, 227);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,733, 8, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,734, 24, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,735, 31, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,736, 33, 2, 228);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,737, 8, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,738, 24, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,739, 31, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,740, 33, 2, 229);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,741, 8, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,742, 24, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,743, 31, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,744, 33, 2, 230);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,745, 8, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,746, 24, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,747, 31, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,748, 33, 2, 231);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,749, 8, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,750, 24, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,751, 31, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,752, 33, 2, 232);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,753, 8, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,754, 24, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,755, 31, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,756, 33, 3, 233);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,757, 8, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,758, 24, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,759, 31, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,760, 33, 3, 234);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,761, 8, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,762, 24, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,763, 31, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,764, 33, 3, 235);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,765, 8, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,766, 24, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,767, 31, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,768, 33, 3, 236);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,769, 8, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,770, 24, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,771, 31, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,772, 33, 3, 237);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,773, 8, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,774, 24, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,775, 31, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,776, 33, 3, 238);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,777, 8, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,778, 24, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,779, 31, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,780, 33, 3, 239);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,781, 8, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,782, 24, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,783, 31, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,784, 33, 3, 240);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,785, 8, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,786, 24, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,787, 31, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,788, 33, 3, 241);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,789, 8, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,790, 24, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,791, 31, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,792, 33, 3, 242);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,793, 1, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,794, 5, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,795, 9, 1, 243);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,796, 1, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,797, 5, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,798, 9, 1, 244);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,799, 1, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,800, 5, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,801, 9, 2, 245);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,802, 1, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,803, 5, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,804, 9, 2, 246);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,805, 1, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,806, 5, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,807, 9, 2, 247);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,808, 1, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,809, 5, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,810, 9, 2, 248);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,811, 1, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,812, 5, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,813, 9, 2, 249);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,814, 1, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,815, 5, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,816, 9, 2, 250);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,817, 1, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,818, 5, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,819, 9, 2, 251);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,820, 1, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,821, 5, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,822, 9, 2, 252);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,823, 1, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,824, 5, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,825, 9, 2, 253);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,826, 1, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,827, 5, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,828, 9, 2, 254);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,829, 1, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,830, 5, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,831, 9, 3, 255);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,832, 1, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,833, 5, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,834, 9, 3, 256);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,835, 1, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,836, 5, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,837, 9, 3, 257);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,838, 1, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,839, 5, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,840, 9, 3, 258);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,841, 1, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,842, 5, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,843, 9, 3, 259);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,844, 1, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,845, 5, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,846, 9, 3, 260);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,847, 1, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,848, 5, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,849, 9, 3, 261);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,850, 1, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,851, 5, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,852, 9, 3, 262);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,853, 1, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,854, 5, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,855, 9, 3, 263);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,856, 1, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,857, 5, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,858, 9, 3, 264);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,859, 4, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,860, 7, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,861, 12, 1, 265);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,862, 4, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,863, 7, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,864, 12, 1, 266);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,865, 4, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,866, 7, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,867, 12, 2, 267);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,868, 4, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,869, 7, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,870, 12, 2, 268);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,871, 4, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,872, 7, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,873, 12, 2, 269);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,874, 4, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,875, 7, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,876, 12, 2, 270);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,877, 4, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,878, 7, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,879, 12, 2, 271);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,880, 4, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,881, 7, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,882, 12, 2, 272);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,883, 4, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,884, 7, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,885, 12, 2, 273);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,886, 4, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,887, 7, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,888, 12, 2, 274);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,889, 4, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,890, 7, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,891, 12, 2, 275);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,892, 4, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,893, 7, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,894, 12, 2, 276);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,895, 4, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,896, 7, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,897, 12, 3, 277);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,898, 4, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,899, 7, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,900, 12, 3, 278);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,901, 4, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,902, 7, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,903, 12, 3, 279);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,904, 4, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,905, 7, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,906, 12, 3, 280);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,907, 4, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,908, 7, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,909, 12, 3, 281);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,910, 4, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,911, 7, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,912, 12, 3, 282);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,913, 4, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,914, 7, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,915, 12, 3, 283);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,916, 4, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,917, 7, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,918, 12, 3, 284);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,919, 4, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,920, 7, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,921, 12, 3, 285);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,922, 4, 3, 286);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,923, 7, 3, 286);");
    inserts.push_back("INSERT INTO licenses (modified_timestamp,is_deleted,id,course_id,class_type_id,faculty_member_id) VALUES (current_timestamp,false,924, 12, 3, 286);");
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

