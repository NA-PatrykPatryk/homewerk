#pragma once

#include "../BetterCandidatesValidator.hpp"
#include "../Candidate.hpp"

class CRequirements: public BetterCandidatesValidator
{
public:
    CRequirements(int threshold)
    : threshold(threshold)
    {}
    bool validate(const Candidate& candidate) override
    {
        return candidate.cFluency >= threshold;
    }
private:
    int threshold;
};