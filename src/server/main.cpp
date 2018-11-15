#include <iostream>
#include <vector>
#include <utility>

#include <ortools/sat/cp_model.h>
#include <ortools/base/logging.h>
#include <ortools/util/proto_tools.h>

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

    ort::sat::CpModelBuilder cp_model_builder;

    std::vector<ort::sat::IntVar> timeslot_of_class(classes.size());

    for(int i=0; i<classes.size(); ++i) {

        timeslot_of_class[i] = cp_model_builder.NewIntVar(ort::Domain(1, timeslots.size()));
    } 

    std::vector<std::vector<ort::sat::IntVar>> room_of_class(classes.size());

    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<classes[i].count(); ++j) {

            auto vecint = d.get_rooms_by_id_to_hold_class(classes[i].id());
            std::vector<int64> veclong(begin(vecint), end(vecint));

            room_of_class[i].push_back(cp_model_builder.NewIntVar(ort::Domain::FromValues(absl::Span<int64>(veclong))));
        }
    }

    std::vector<std::vector<ort::sat::IntVar>> faculty_member_for_class(classes.size());

    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<classes[i].count(); ++j) {
       
            auto vecint = d.get_faculty_members_by_id_licensed_to_teach_class(classes[i].id());
            std::vector<int64> veclong(begin(vecint), end(vecint));
    
            faculty_member_for_class[i].push_back(cp_model_builder.NewIntVar(ort::Domain::FromValues(absl::Span<int64>(veclong))));
        }
    }

    std::vector<ort::sat::IntVar> timeslot_and_room_pair_is_unique;

    for(int i=0; i<classes.size(); ++i) {

        for(int j=0; j<room_of_class[i].size(); ++j) {

            timeslot_and_room_pair_is_unique.push_back(

                cp_model_builder.NewIntVar(ort::Domain(1, (timeslots.size() + 1) * (rooms.size() + 1)))
            );

            std::vector<ort::sat::IntVar> vars;
            vars.push_back(room_of_class[i][j]);
            vars.push_back(timeslot_of_class[i]);
            
            std::vector<int64> coeffs;
            coeffs.push_back(timeslots.size() + 1);
            coeffs.push_back(1);
            
            cp_model_builder.AddEquality(

                timeslot_and_room_pair_is_unique[timeslot_and_room_pair_is_unique.size() - 1],

                ort::sat::LinearExpr::ScalProd(absl::Span<ort::sat::IntVar>(vars), absl::Span<int64>(coeffs))
            );
        }
    }

    cp_model_builder.AddAllDifferent(absl::Span<ort::sat::IntVar>(timeslot_and_room_pair_is_unique));

    std::vector<ort::sat::IntVar> timeslot_and_faculty_member_pair_is_unique;

    for(int i=0; i<classes.size(); ++i) {
        for(int j=0; j<faculty_member_for_class[i].size(); ++j) {

            timeslot_and_faculty_member_pair_is_unique.push_back(

                cp_model_builder.NewIntVar(ort::Domain(1, (timeslots.size() + 1) * (faculty_members.size() + 1)))
            );


            std::vector<ort::sat::IntVar> vars;
            vars.push_back(faculty_member_for_class[i][j]);
            vars.push_back(timeslot_of_class[i]);

            std::vector<int64> coeffs;
            coeffs.push_back(timeslots.size() + 1);
            coeffs.push_back(1);

            cp_model_builder.AddEquality(
            
                timeslot_and_faculty_member_pair_is_unique[timeslot_and_faculty_member_pair_is_unique.size() - 1], 

                ort::sat::LinearExpr::ScalProd(absl::Span<ort::sat::IntVar>(vars), absl::Span<int64>(coeffs))
            );
        }
    }

    cp_model_builder.AddAllDifferent(absl::Span<ort::sat::IntVar>(timeslot_and_faculty_member_pair_is_unique));

    std::vector<ort::sat::IntVar> timeslot_and_year_pair_is_unique(classes.size());

    for(int i=0; i<classes.size(); ++i) {

        timeslot_and_year_pair_is_unique[i] =

            cp_model_builder.NewIntVar(ort::Domain(1, (timeslots.size() + 1) * (years.size() + 1)));

        auto linear_expr = ort::sat::LinearExpr((timeslots.size() + 1) * d.get_year_by_id_for_class(classes[i].id()));
        linear_expr.AddVar(timeslot_of_class[i]);

        cp_model_builder.AddEquality(

            timeslot_and_year_pair_is_unique[i],

            linear_expr
        );
    }

    cp_model_builder.AddAllDifferent(absl::Span<ort::sat::IntVar>(timeslot_and_year_pair_is_unique));

    std::vector<ort::sat::IntVar> x;
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

    ort::sat::CpSolverResponse result = ort::sat::Solve(cp_model_builder);

    std::cout << ort::FullProtocolMessageAsString(result, 4) << std::endl;

    std::vector<chronos::Proposal> proposals;

    for(int i=0; i<classes.size(); ++i) {
   
        auto timeslot_id = ort::sat::SolutionIntegerValue(result, timeslot_of_class[i]);
        auto year_id = d.get_year_by_id_for_class(classes[i].id());
        auto class_id = classes[i].id();

        std::vector<int> room_ids;
        std::vector<std::string> room_names;
        for(int j=0; j<room_of_class[i].size(); ++j) {
            int id = ort::sat::SolutionIntegerValue(result, room_of_class[i][j]);
            room_ids.push_back(id);
            room_names.push_back(rooms[id-1].name());
        }

        std::vector<int> faculty_member_ids;
        std::vector<std::string> faculty_member_names;
        for(int j=0; j<faculty_member_for_class[i].size(); ++j) {
            int id = ort::sat::SolutionIntegerValue(result, faculty_member_for_class[i][j]);
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

    return 0;
}
