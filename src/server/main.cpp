#include <iostream>
#include <vector>

#include <ortools/constraint_solver/constraint_solver.h>

#include "server/database_manual.h"
#include "server/proposal.h"

namespace ort = operations_research;

int main(int argc, char *argv[]) {
    
    // google::InitGoogleLogging(argv[0]);

    std::string user = "nemkin";
    std::string pass = "nemkin";

    chronos::DatabaseManual d(user, pass);
    
    d.test(); 
    d.destroy(); 
    d.init(); 
    d.fill();

    auto timeslots = d.get_timeslots();
    auto classes = d.get_classes();
    auto rooms = d.get_rooms();
    auto faculty_members = d.get_faculty_members();
    auto years = d.get_years();

    ort::Solver s("chronos_solver");

    std::vector<ort::IntVar*> timeslot_of_class;
    timeslot_of_class.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {
        timeslot_of_class[i] =
            s.MakeIntVar(
                1,
                timeslots.size(),
                classes[i].name()
            );
    } 

    std::vector<ort::IntVar*> room_of_class;
    room_of_class.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {
        room_of_class[i] =
            s.MakeIntVar(
                d.get_rooms_by_id_to_hold_class(
                    classes[i].id()
                ),
                classes[i].name()
            );
    }

    std::vector<ort::IntVar*> faculty_member_for_class;
    faculty_member_for_class.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {
        faculty_member_for_class[i] =
            s.MakeIntVar(
                d.get_faculty_members_by_id_licensed_to_teach_class(
                    classes[i].id()
                ),
                classes[i].name()
            );
    }

    std::cout << "Number of variables: " << 3 * classes.size() << std::endl;

    std::vector<ort::IntVar*> timeslot_and_room_pair_is_unique;
    timeslot_and_room_pair_is_unique.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {

        timeslot_and_room_pair_is_unique[i] =
            s.MakeIntVar(
                1,
                (timeslots.size() + 1) * (rooms.size() + 1)
            );

        s.AddConstraint(
            s.MakeEquality(
                timeslot_and_room_pair_is_unique[i],
                s.MakeSum(
                    s.MakeProd(
                        room_of_class[i],
                        timeslots.size() + 1
                    ),
                    timeslot_of_class[i]
                )
            )
        );
    }
    s.AddConstraint(s.MakeAllDifferent(timeslot_and_room_pair_is_unique));

    std::vector<ort::IntVar*> timeslot_and_faculty_member_pair_is_unique;
    timeslot_and_faculty_member_pair_is_unique.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {

        timeslot_and_faculty_member_pair_is_unique[i] =
            s.MakeIntVar(
                1,
                (timeslots.size() + 1) * (faculty_members.size() + 1)
            );

        s.AddConstraint(
            s.MakeEquality(
                timeslot_and_faculty_member_pair_is_unique[i], 
                s.MakeSum(
                    s.MakeProd(
                        faculty_member_for_class[i],
                        timeslots.size() + 1
                    ),
                    timeslot_of_class[i]
                )
            )
        );
    }
    s.AddConstraint(s.MakeAllDifferent(timeslot_and_faculty_member_pair_is_unique));

    std::vector<ort::IntVar*> timeslot_and_year_pair_is_unique;
    timeslot_and_year_pair_is_unique.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {

        timeslot_and_year_pair_is_unique[i] =
            s.MakeIntVar(
                1,
                (timeslots.size() + 1) * (years.size() + 1)
            );

        s.AddConstraint(
            s.MakeEquality(
                timeslot_and_year_pair_is_unique[i],
                s.MakeSum(
                    timeslot_of_class[i],
                    (timeslots.size() + 1) *
                    d.get_year_by_id_for_class(classes[i].id())
                )
            )
        );
    }
    s.AddConstraint(s.MakeAllDifferent(timeslot_and_year_pair_is_unique));

    std::vector<ort::IntVar*> x;
    x.insert(
        x.end(),
        timeslot_of_class.begin(),
        timeslot_of_class.end()
    );
    x.insert(
        x.end(),
        room_of_class.begin(),
        room_of_class.end()
    );
    x.insert(
        x.end(),
        faculty_member_for_class.begin(),
        faculty_member_for_class.end()
    );
    x.insert(
        x.end(),
        timeslot_and_room_pair_is_unique.begin(),
        timeslot_and_room_pair_is_unique.end()
    );
    x.insert(
        x.end(),
        timeslot_and_faculty_member_pair_is_unique.begin(),
        timeslot_and_faculty_member_pair_is_unique.end()
    );
    x.insert(
        x.end(),
        timeslot_and_year_pair_is_unique.begin(),
        timeslot_and_year_pair_is_unique.end()
    );

    ort::DecisionBuilder* const db = s.MakePhase(x, ort::Solver::CHOOSE_FIRST_UNBOUND, ort::Solver::ASSIGN_MIN_VALUE);
    
    s.NewSearch(db);
    
    CHECK(s.NextSolution());

    for(int i=0; i<classes.size(); ++i) {
   
        auto timeslot_id = timeslot_of_class[i] -> Value();
        auto year_id = d.get_year_by_id_for_class(classes[i].id());
        auto class_id = classes[i].id();
        auto room_id = room_of_class[i] -> Value();
        auto faculty_member_id = faculty_member_for_class[i] -> Value();

        chronos::Proposal p(
            timeslot_id,
            year_id,
            class_id,
            room_id,
            faculty_member_id,
            timeslots[timeslot_id-1].name(),
            years[year_id-1].name(),
            classes[class_id-1].name(),
            rooms[room_id-1].name(),
            faculty_members[faculty_member_id-1].name()
        );

        std::cout << p.to_string() << std::endl << std::endl;
    }

    LOG(INFO) << s.DebugString();
    s.EndSearch();
    return 0;
}
