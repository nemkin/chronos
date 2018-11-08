#include <iostream>
#include <vector>

#include <ortools/constraint_solver/constraint_solver.h>

#include "server/database_manual.h"

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

    auto classes = d.get_classes();
    auto proposals = d.get_proposals();
    int n = 20;

    ort::Solver s("chronos_solver");

    auto logger = s.MakeSearchLog(1000000);
    std::vector<ort::IntVar*> x;
    x.resize(n);

    for(int i=0; i<n; ++i) {
       x[i] = s.MakeBoolVar(proposals[i].to_string()); 
    }
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            
            if(
                proposals[i].class_id() != proposals[j].class_id() && 
                proposals[i].timeslot_id() == proposals[j].timeslot_id()) {
           
                if(
                    proposals[i].faculty_member_id() == proposals[j].faculty_member_id() ||
                    proposals[i].room_id() == proposals[j].room_id() ||
                    proposals[i].year_id() == proposals[j].year_id()) {
                    
                    s.AddConstraint(s.MakeEquality(s.MakeProd(x[i], x[j]), 0));
                }
            }
        }
    }

    std::vector<ort::IntExpr*> sum_of_accepted_proposals_per_class;
    
    sum_of_accepted_proposals_per_class.resize(classes.size() + 1);
    for(int i=0; i<n; ++i) {

        auto id = proposals[i].class_id();
        if(sum_of_accepted_proposals_per_class[id] == nullptr) {
            sum_of_accepted_proposals_per_class[id] = x[i];
        } else {
            sum_of_accepted_proposals_per_class[id] = s.MakeSum(sum_of_accepted_proposals_per_class[id], x[i]);
        }
    }

    for(auto sum : sum_of_accepted_proposals_per_class) {
        if(sum != nullptr) {
            s.AddConstraint(s.MakeEquality(sum, 1));
        }
    }

    ort::DecisionBuilder* const db = s.MakePhase(x, ort::Solver::CHOOSE_FIRST_UNBOUND, ort::Solver::ASSIGN_MIN_VALUE);
    
    s.NewSearch(db);
    
    CHECK(s.NextSolution());

    for(int i=0; i<n; ++i) {
        
       std::cout << x[i]->name() << std::endl << x[i]->Value() << ' ' << std::endl;
    }

    LOG(INFO) << s.DebugString();
    s.EndSearch();
    return 0;
}
