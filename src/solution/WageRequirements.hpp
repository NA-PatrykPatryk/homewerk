#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class WageRequirements: public BetterCandidatesValidator
{
public:
    WageRequirements(int threshold)
    : threshold(threshold) {}
    
    bool validate(const Candidate& candidate) override
    {
        return candidate.preferredWage <= threshold;
    }
private:
    int threshold;
};