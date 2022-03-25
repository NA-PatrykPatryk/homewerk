#include <vector>
#include <iostream>

#include "Application.hpp"
#include "Candidate.hpp"
#include "solution/CooperationNeeded.hpp"
#include "solution/CppRequirements.hpp"
#include "solution/CRequirements.hpp"
#include "solution/WageRequirements.hpp"

int main()
{
    std::vector<Candidate> candidates{
        {"Adelajda", 15, 87, 0, 12000},
        {"Brunhilda", 85, 42, 1, 11000},
        {"Ciechosław", 97, 92, 1, 25000},
        {"Domażyr", 91, 45, 0, 10000}};

    Application app(candidates);
    app.setRequirements(std::make_unique<CooperationNeeded>());
    app.setRequirements(std::make_unique<CppRequirements>(20));
    app.setRequirements(std::make_unique<CRequirements>(0));
    app.setRequirements(std::make_unique<WageRequirements>(15000));
    
    for (auto candidate: app.getFilteredCandidates())
    {
        std::cout << "candidate " << candidate.name << " seems to fit" << std::endl;
    }

}
