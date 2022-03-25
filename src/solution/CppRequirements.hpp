#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CppRequirements: public BetterCandidatesValidator
{
public:
    CppRequirements(int threshold)
    : threshold(threshold) {}
    bool validate(const Candidate& candidate) override
    {
        return candidate.cppFluency >= threshold;
    }
private:
    int threshold;
};