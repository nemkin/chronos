#pragma once

#ifndef __DATABASE__H__
#define __DATABASE__H__

#include <string>
#include <vector>

#include <pqxx/pqxx>

#include "model/generated/entities/timeslot.h"
#include "model/generated/entities/location.h"
#include "model/generated/entities/class_type.h"
#include "model/generated/entities/year.h"
#include "model/generated/entities/department.h"
#include "model/generated/entities/course.h"
#include "model/generated/entities/room.h"
#include "model/generated/entities/class.h"
#include "model/generated/entities/faculty_member.h"
#include "model/generated/entities/license.h"

namespace chronos {

class Database {

public:

    Database(
        std::string p_user,
        std::string p_pass,
        std::string p_host = "10.240.2.125",
        std::string p_database = "chronos"
    );

    std::vector<Timeslot> get_timeslots();
    std::vector<Location> get_locations();
    std::vector<ClassType> get_class_types();
    std::vector<Year> get_years();
    std::vector<Department> get_departments();
    std::vector<Course> get_courses();
    std::vector<Room> get_rooms();
    std::vector<Class> get_classes();
    std::vector<FacultyMember> get_faculty_members();
    std::vector<License> get_licenses();

    void test();
    void init();
    void fill();
    void destroy();

protected:

    std::string _user;
    pqxx::connection _db;

};

}

#endif //__DATABASE__H__

