#include "database.h"

#include <iostream>

using namespace chronos;

Database::Database(
    std::string user,
    std::string password,
    std::string host,
    std::string database
) :
    _db(
        "host = " + host + " "
        "dbname = " + database + " " 
        "user = " + user + " "
        "password = " + password) {
}

std::vector<Department> Database::get_departments() {

    std::vector<Department> ret;

    try {

        pqxx::nontransaction n(_db);

        pqxx::result r(n.exec("SELECT * FROM departments;"));

        for(auto i = r.begin(); i != r.end(); ++i) {

            int id = i[0].as<int>();
            std::string name = i[1].as<std::string>();
            std::string modified_timestamp = i[2].as<std::string>();
            bool is_deleted = i[3].as<bool>();

            Department d(
                id,
                name,
                modified_timestamp,
                is_deleted
            );
            
            ret.push_back(d);
        }

    } catch (std::exception& e) {

        std::cerr << e.what();
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
        "CREATE TABLE locations ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "latitude DOUBLE PRECISION NOT NULL, "
            "longitude DOUBLE PRECISION NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE distances ( "
            "id SERIAL PRIMARY KEY, "
            "location_id_1 INTEGER REFERENCES locations(id) NOT NULL,"
            "location_id_2 INTEGER REFERENCES locations(id) NOT NULL,"
            "distance_minutes DOUBLE PRECISION NOT NULL,"
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE room_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "size INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE rooms ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "room_type_id INTEGER REFERENCES room_types(id) NOT NULL, "
            "size INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE departments ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE faculty_members ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "department_id INTEGER REFERENCES departments(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE majors ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE grades ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "major_id INTEGER REFERENCES majors(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semester_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE semesters ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "semester_type_id INTEGER REFERENCES semester_types(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE courses ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "grade_id INTEGER REFERENCES grades(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE class_types ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE licenses ( "
            "id SERIAL PRIMARY KEY, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "faculty_member_id INTEGER REFERENCES faculty_members(id) NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
    );

    creates.push_back(
        "CREATE TABLE classes ( "
            "id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "class_type_id INTEGER REFERENCES class_types(id) NOT NULL, "
            "course_id INTEGER REFERENCES courses(id) NOT NULL, "
            "lesson_count INTEGER NOT NULL, "
            "regularity INTEGER NOT NULL, "
            "maximum_student_count INTEGER NOT NULL, "
            "modified_timestamp TIMESTAMP NOT NULL, "
            "is_deleted BOOLEAN DEFAULT false NOT NULL);"
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

    drops.push_back("DROP TABLE locations CASCADE;"); 
    drops.push_back("DROP TABLE distances CASCADE;"); 
    drops.push_back("DROP TABLE room_types CASCADE;"); 
    drops.push_back("DROP TABLE rooms CASCADE;");
    drops.push_back("DROP TABLE departments CASCADE;"); 
    drops.push_back("DROP TABLE faculty_members CASCADE;"); 
    drops.push_back("DROP TABLE majors CASCADE;"); 
    drops.push_back("DROP TABLE grades CASCADE;"); 
    drops.push_back("DROP TABLE semester_types CASCADE;"); 
    drops.push_back("DROP TABLE semesters CASCADE;"); 
    drops.push_back("DROP TABLE courses CASCADE;"); 
    drops.push_back("DROP TABLE class_types CASCADE;"); 
    drops.push_back("DROP TABLE licenses CASCADE;");
    drops.push_back("DROP TABLE classes CASCADE;");

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


