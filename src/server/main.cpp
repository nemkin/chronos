#include <iostream>
#include <vector>
#include <utility>
#include <unistd.h>

#include <ortools/constraint_solver/constraint_solver.h>
#include <ortools/base/logging.h>

#include "server/database_manual.h"
#include "server/timetable.h"

namespace ort = operations_research;

int main(int argc, char *argv[]) {
   
    //google::InitGoogleLogging(argv[0]);
 
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

    std::vector<std::vector<ort::IntVar*>> room_of_class;
    room_of_class.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<classes[i].count(); ++j) {

            room_of_class[i].push_back(
                s.MakeIntVar(
                    d.get_rooms_by_id_to_hold_class(
                        classes[i].id()
                    ),
                    classes[i].name()
                )
            );
        }
    }

    std::vector<std::vector<ort::IntVar*>> faculty_member_for_class;
    faculty_member_for_class.resize(classes.size());
    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<classes[i].count(); ++j) {
        
            faculty_member_for_class[i].push_back(
                s.MakeIntVar(
                    d.get_faculty_members_by_id_licensed_to_teach_class(
                        classes[i].id()
                    ),
                    classes[i].name()
                )
            );
        }
    }

    std::vector<ort::IntVar*> timeslot_and_room_pair_is_unique;
    for(int i=0; i<classes.size(); ++i) {

        for(int j=0; j<room_of_class[i].size(); ++j) {

            timeslot_and_room_pair_is_unique.push_back(
                s.MakeIntVar(
                    1,
                    (timeslots.size() + 1) * (rooms.size() + 1)
                )
            );


            s.AddConstraint(
                s.MakeEquality(
                    timeslot_and_room_pair_is_unique[timeslot_and_room_pair_is_unique.size() - 1],
                    s.MakeSum(
                        s.MakeProd(
                            room_of_class[i][j],
                            timeslots.size() + 1
                        ),
                        timeslot_of_class[i]
                    )
                )
            );
        }
    }
    s.AddConstraint(s.MakeAllDifferent(timeslot_and_room_pair_is_unique));

    std::vector<ort::IntVar*> timeslot_and_faculty_member_pair_is_unique;
    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<faculty_member_for_class[i].size(); ++j) {

            timeslot_and_faculty_member_pair_is_unique.push_back(
                s.MakeIntVar(
                    1,
                    (timeslots.size() + 1) * (faculty_members.size() + 1)
                )
            );

            s.AddConstraint(
                s.MakeEquality(
                    timeslot_and_faculty_member_pair_is_unique[timeslot_and_faculty_member_pair_is_unique.size() - 1], 
                    s.MakeSum(
                        s.MakeProd(
                            faculty_member_for_class[i][j],
                            timeslots.size() + 1
                        ),
                        timeslot_of_class[i]
                    )
                )
            );
        }
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
    for(int j=0; j<room_of_class.size(); ++j) {
        x.insert(
            x.end(),
            room_of_class[j].begin(),
            room_of_class[j].end()
        );
    }
    for(int j=0; j<faculty_member_for_class.size(); ++j) {
        x.insert(
            x.end(),
            faculty_member_for_class[j].begin(),
            faculty_member_for_class[j].end()
        );
    }
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

    std::cout << "Number of variables: " << x.size() << std::endl;
    ort::DecisionBuilder* const db = s.MakePhase(x, ort::Solver::CHOOSE_FIRST_UNBOUND, ort::Solver::ASSIGN_MIN_VALUE);
    
    auto search_monitor = s.MakeSearchLog(10000000); 
    std::vector<ort::SearchMonitor*> monitors;
    monitors.push_back(search_monitor);

    s.NewSearch(db,monitors);
    CHECK(s.NextSolution());

    std::vector<chronos::Proposal> proposals;

    for(int i=0; i<classes.size(); ++i) {
   
        auto timeslot_id = timeslot_of_class[i] -> Value();
        auto year_id = d.get_year_by_id_for_class(classes[i].id());
        auto class_id = classes[i].id();

        std::vector<int> room_ids;
        std::vector<std::string> room_names;
        for(int j=0; j<room_of_class[i].size(); ++j) {
            int id = room_of_class[i][j] -> Value();
            room_ids.push_back(id);
            room_names.push_back(rooms[id-1].name());
        }

        std::vector<int> faculty_member_ids;
        std::vector<std::string> faculty_member_names;
        for(int j=0; j<faculty_member_for_class[i].size(); ++j) {
            int id = faculty_member_for_class[i][j] -> Value();
            faculty_member_ids.push_back(id);
            faculty_member_names.push_back(faculty_members[id-1].name());
        }

        chronos::Proposal p(
            timeslot_id,
            year_id,
            class_id,
            room_ids,
            faculty_member_ids,
            timeslots[timeslot_id-1].name(),
            years[year_id-1].name(),
            classes[class_id-1].name(),
            room_names,
            faculty_member_names
        );

        proposals.push_back(p);
    }

    std::map<int, chronos::Timetable> year_timetables;
    std::map<int, chronos::Timetable> faculty_member_timetables;
    std::map<int, chronos::Timetable> room_timetables;

    for(auto proposal : proposals) {
  
        year_timetables[proposal.year_id()].add(proposal);

        for(auto faculty_member_id : proposal.faculty_member_ids())
            faculty_member_timetables[faculty_member_id].add(proposal);
        for(auto room_id : proposal.room_ids()) {
            room_timetables[room_id].add(proposal);
        }
    }

    for(auto t : year_timetables) {

        std::cout << years[t.first-1].to_string() << std::endl;
        std::cout << t.second.to_string() << std::endl << std::endl;
    }

    for(auto t : faculty_member_timetables) {

        std::cout << faculty_members[t.first-1].to_string() << std::endl;
        std::cout << t.second.to_string() << std::endl << std::endl;
    }

    for(auto t : room_timetables) {

        std::cout << rooms[t.first-1].to_string() << std::endl;
        std::cout << t.second.to_string() << std::endl << std::endl;
    }

    LOG(INFO) << s.DebugString();
    s.EndSearch();
    return 0;
}
