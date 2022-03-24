#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CooperationNeeded: public BetterCandidatesValidator
{
public:
    bool validate(const Candidate& candidate) override
    {
        return candidate.cooperative == true;
    }
};