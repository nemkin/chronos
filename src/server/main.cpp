#include <iostream>
#include <vector>

#include <ortools/constraint_solver/constraint_solver.h>

#include "model/generated/database/database.h"

namespace ort = operations_research;

int main(int argc, char *argv[]) {
    
    // google::InitGoogleLogging(argv[0]);

    std::string user = "nemkin";
    std::string pass = "nemkin";

    chronos::Database d(user, pass);
    
    d.test(); 
    d.destroy(); 
    d.init(); 
    d.fill();

    auto departments = d.get_departments();
    auto courses = d.get_courses();
    auto years = d.get_years();

    int slots = 10;
    int n = courses.size();
    ort::Solver s("solvy");

    std::vector<ort::IntVar*> x;

    x.resize(n * slots);
    for(int i=0; i<n; ++i) {
        
        for(int j=0; j<slots; ++j) {
           x[i * slots + j] = s.MakeIntVar(0, 1, "course " + courses[i].name() + " slot " + std::to_string(j)); 
        }
    }

    std::vector<ort::IntExpr*> sum_for_slots;
    sum_for_slots.resize(n);

    for(int i=0; i<n; ++i) {
        sum_for_slots[i] = x[i * slots + 0];
    }

    for(int i=0; i<n; ++i) {
        for(int j=1; j<slots; ++j) {
            sum_for_slots[i] =  s.MakeSum(sum_for_slots[i], x[i * slots + j]);
        }
    }

    std::vector<ort::Constraint*> sum_is_one;
    sum_is_one.resize(n);
    for(int i=0; i<n; ++i) {
        sum_is_one[i] = s.MakeEquality(sum_for_slots[i], 1);
        s.AddConstraint(sum_is_one[i]);
    }

    ort::DecisionBuilder* const db = s.MakePhase(x, ort::Solver::CHOOSE_FIRST_UNBOUND, ort::Solver::ASSIGN_MIN_VALUE);
    
    s.NewSearch(db);
    
    CHECK(s.NextSolution());

    for(int j=0; j<slots; ++j) {

        for(int i=0; i<n; ++i) {
        
           std::cout << x[i * slots + j]->Value() << ' '; 
        }
        std::cout << std::endl;
    }

    LOG(INFO) << s.DebugString();
    s.EndSearch();
    return 0;
}
