#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CRequirements: public BetterCandidatesValidator
{
public:
    bool validate(const Candidate& candidate) override
    {
        return candidate.cFluency >= 0;
    }
};