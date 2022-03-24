#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CppRequirements: public BetterCandidatesValidator
{
public:
    bool validate(const Candidate& candidate) override
    {
        return candidate.cppFluency >= 20;
    }
};