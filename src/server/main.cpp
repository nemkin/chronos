#include <iostream>
#include <vector>
#include <utility>

#include <ortools/sat/cp_model.h>
#include <ortools/base/logging.h>
#include <ortools/util/proto_tools.h>

#include "model/manual/database_service.h"
#include "model/manual/timetable.h"

namespace ort = operations_research;

int main(int argc, char *argv[]) {
   
    // google::InitGoogleLogging(argv[0]);

    unsigned int variable_count = 0;
    unsigned int non_seminars_parallel = 5;

    // Database init
 
    chronos::DatabaseService::init(
        "nemkin",
        "nemkin",
        "10.240.2.125",
        "chronos"
    );

    chronos::DatabaseService::instance().test(); 
    chronos::DatabaseService::instance().destroy(); 
    chronos::DatabaseService::instance().init(); 
    chronos::DatabaseService::instance().fill();

    auto timeslots = 
        chronos::DatabaseService::instance()
            .get_timeslots();
    auto classes =
        chronos::DatabaseService::instance()
            .get_classes();
    auto rooms =
        chronos::DatabaseService::instance()
            .get_rooms();
    auto faculty_members =
        chronos::DatabaseService::instance()
            .get_faculty_members();
    auto years =
        chronos::DatabaseService::instance()
            .get_years();

    ort::sat::CpModelBuilder cp_model_builder;


    // TIMESLOT VARS
    
    std::vector<ort::sat::IntVar> timeslot_of_class(
        classes.size()
    );

    for(unsigned int i=0; i<classes.size(); ++i) {

        timeslot_of_class[i] =
            cp_model_builder.NewIntVar(
                ort::Domain(
                    1,
                    timeslots.size()
                )
            );
        ++variable_count;
    } 


    // ROOM VARS

    std::vector<ort::sat::IntVar> room_of_class(
        classes.size()
    );

    for(unsigned int i=0; i<classes.size(); ++i) {

        auto vecint =
            chronos::DatabaseService::instance()
                .get_rooms_by_id_to_hold_class(
                    classes[i].id()
                );
        std::vector<int64> veclong(
            begin(vecint),
            end(vecint)
        );

        room_of_class[i] = 
            cp_model_builder.NewIntVar(
                ort::Domain::FromValues(
                    absl::Span<int64>(veclong)
                    )
                );
        ++variable_count;
    }


    // FACULTY_MEMBER_VARS

    std::vector<ort::sat::IntVar> faculty_member_for_class(
        classes.size()
    );

    for(unsigned int i=0; i<classes.size(); ++i) {
       
       auto vecint =
           chronos::DatabaseService::instance()
               .get_faculty_members_by_id_licensed_to_teach_class(
                   classes[i].id()
               );
       std::vector<int64> veclong(
           begin(vecint),
           end(vecint)
       );
    
       faculty_member_for_class[i] =
           cp_model_builder.NewIntVar(
               ort::Domain::FromValues(
                   absl::Span<int64>(veclong)
               )
           );
       ++variable_count;
    }


    // Unique constraint for TIMESLOT X ROOM

    std::vector<ort::sat::IntVar> timeslot_and_room_pair_is_unique;

    for(unsigned int i=0; i<classes.size(); ++i) {

        timeslot_and_room_pair_is_unique.push_back(
            cp_model_builder.NewIntVar(
                ort::Domain(
                    1,
                    (timeslots.size() + 1) *
                    (rooms.size() + 1)
                )
            )
        );
        ++variable_count;

        std::vector<ort::sat::IntVar> vars;
        vars.push_back(room_of_class[i]);
        vars.push_back(timeslot_of_class[i]);
        
        std::vector<int64> coeffs;
        coeffs.push_back(timeslots.size() + 1);
        coeffs.push_back(1);
        
        cp_model_builder.AddEquality(

            timeslot_and_room_pair_is_unique.back(),

            ort::sat::LinearExpr::ScalProd(
                absl::Span<ort::sat::IntVar>(vars),
                absl::Span<int64>(coeffs)
            )
        );
    }

    cp_model_builder.AddAllDifferent(
        absl::Span<ort::sat::IntVar>(
            timeslot_and_room_pair_is_unique
        )
    );


    // Unique constraint for TIMESLOT X FACULTY_MEMBER

    std::vector<ort::sat::IntVar> timeslot_and_faculty_member_pair_is_unique;

    for(unsigned int i=0; i<classes.size(); ++i) {

        timeslot_and_faculty_member_pair_is_unique.push_back(
            cp_model_builder.NewIntVar(
                ort::Domain(
                    1,
                    (timeslots.size() + 1) *
                    (faculty_members.size() + 1)
                )
            )
        );
        ++variable_count;

        std::vector<ort::sat::IntVar> vars;
        vars.push_back(faculty_member_for_class[i]);
        vars.push_back(timeslot_of_class[i]);

        std::vector<int64> coeffs;
        coeffs.push_back(timeslots.size() + 1);
        coeffs.push_back(1);

        cp_model_builder.AddEquality(
        
            timeslot_and_faculty_member_pair_is_unique.back(), 

            ort::sat::LinearExpr::ScalProd(
                absl::Span<ort::sat::IntVar>(vars),
                absl::Span<int64>(coeffs)
            )
        );
    }
    
    cp_model_builder.AddAllDifferent(
        absl::Span<ort::sat::IntVar>(
            timeslot_and_faculty_member_pair_is_unique
        )
    );


    // Unique constraint for TIMESLOT X YEAR

    std::vector<ort::sat::IntVar> timeslot_and_year_pair_is_unique;

    for(unsigned int i=0; i<classes.size(); ++i) {

        if(classes[i].class_type_id() == 1) {

            for(unsigned int j=0; j<non_seminars_parallel; ++j) {
 
                timeslot_and_year_pair_is_unique.push_back(
                    cp_model_builder.NewIntVar(
                        ort::Domain(
                            1,
                            (timeslots.size() + 1) *
                            (years.size() + 1) *
                            non_seminars_parallel
                        )
                    )
                );
                ++variable_count;

                std::vector<ort::sat::IntVar> vars;
                vars.push_back(
                    timeslot_of_class[i]
                );

                std::vector<int64> coeffs;
                coeffs.push_back(
                    non_seminars_parallel *
                    (years.size() + 1)
                );
            
                std::vector<int64> consts;
                consts.push_back(
                    j *
                    (years.size() + 1)
                );
                consts.push_back(
                    chronos::DatabaseService::instance()
                        .get_year_by_id_for_class(
                            classes[i].id()
                        )
                    );

                auto expr = 
                    ort::sat::LinearExpr::ScalProd(
                        absl::Span<ort::sat::IntVar>(vars),
                        absl::Span<int64>(coeffs)
                    );
                for(auto constant : consts) {
                    expr.AddConstant(constant);
                }

                cp_model_builder.AddEquality(
                    timeslot_and_year_pair_is_unique.back(),
                    expr
                );
           
            }

        } else {
          
            auto uniqueness = 
                cp_model_builder
                    .NewIntVar(
                        ort::Domain(
                            0,
                            non_seminars_parallel-1
                        )
                    );
            ++variable_count;
 
            timeslot_and_year_pair_is_unique.push_back(
                cp_model_builder.NewIntVar(
                    ort::Domain(
                        1,
                        (timeslots.size() + 1) *
                        (years.size() + 1) *
                        non_seminars_parallel
                    )
                )
            );
            ++variable_count;

            std::vector<ort::sat::IntVar> vars;
            vars.push_back(
                timeslot_of_class[i]
            );
            vars.push_back(
                uniqueness
            );

            std::vector<int64> coeffs;
            coeffs.push_back(
                non_seminars_parallel *
                (years.size() + 1)
            );
            coeffs.push_back(
                years.size() + 1
            );
           
            std::vector<int64> consts;
            consts.push_back(
                chronos::DatabaseService::instance()
                    .get_year_by_id_for_class(
                        classes[i].id()
                    )
                );

            auto expr =
                ort::sat::LinearExpr::ScalProd(
                    absl::Span<ort::sat::IntVar>(vars),
                    absl::Span<int64>(coeffs)
                );
            for(auto constant : consts) {
                expr.AddConstant(constant);
            }

            cp_model_builder.AddEquality(
                timeslot_and_year_pair_is_unique.back(),
                expr
            );
        }
    }

    cp_model_builder.AddAllDifferent(
        absl::Span<ort::sat::IntVar>(
            timeslot_and_year_pair_is_unique
        )
    );

    std::cout << "Number of variables: " << variable_count << std::endl;

    ort::sat:: Model model;

    int num_solutions = 0;
    model.Add(
        ort::sat::NewFeasibleSolutionObserver(
            [&](const ort::sat::CpSolverResponse& r) {

                ++ num_solutions;
                LOG(INFO) << num_solutions;
                LOG(INFO) << ort::FullProtocolMessageAsString(r, 4);
            }
        )
    );

    ort::sat::SatParameters parameters;
    parameters.set_num_search_workers(3);

    model.Add(
        ort::sat::NewSatParameters(
            parameters
        )
    );

    ort::sat::CpSolverResponse result =
        ort::sat::SolveWithModel(
            cp_model_builder,
            &model
        );

    std::cout << ort::FullProtocolMessageAsString(result, 4) << std::endl;

    std::vector<chronos::Proposal> proposals;

    for(unsigned int i=0; i<classes.size(); ++i) {
   
        auto timeslot_id = 
            ort::sat::SolutionIntegerValue(
                result,
                timeslot_of_class[i]
            );

        auto year_id = 
            chronos::DatabaseService::instance()
                .get_year_by_id_for_class(
                    classes[i].id()
                );

        auto class_id = 
            classes[i]
                .id();

        auto room_id =
            ort::sat::SolutionIntegerValue(
                result,
                room_of_class[i]
            );

        auto faculty_member_id =
            ort::sat::SolutionIntegerValue(
                result,
                faculty_member_for_class[i]
            );

        auto class_type_id =
            classes[i]
                .class_type_id();

        chronos::Proposal p(
            timeslot_id,
            year_id,
            class_id,
            room_id,
            faculty_member_id,
            class_type_id,
            timeslots[timeslot_id-1].name(),
            years[year_id-1].name(),
            classes[class_id-1].name(),
            rooms[room_id-1].name(),
            faculty_members[faculty_member_id-1].name()
        );

        proposals.push_back(p);
    }

    std::map<int, chronos::Timetable> year_timetables;
    std::map<int, chronos::Timetable> faculty_member_timetables;
    std::map<int, chronos::Timetable> room_timetables;

    for(auto proposal : proposals) {
  
        year_timetables[proposal.year_id()].add(proposal);
        faculty_member_timetables[proposal.faculty_member_id()].add(proposal);
        room_timetables[proposal.room_id()].add(proposal);
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

    chronos::DatabaseService::destroy();

    return 0;
}
