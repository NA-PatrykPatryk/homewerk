#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class WageRequirements: public BetterCandidatesValidator
{
public:
    bool validate(const Candidate& candidate) override
    {
        return candidate.preferredWage <= 15000;
    }
};