#pragma once
#include <memory>
#include "Candidate.hpp"

class BetterCandidatesValidator
{
public:
    void add(std::unique_ptr<BetterCandidatesValidator> validator)
    {
        if (next != nullptr)
            next->add(move(validator));
        else
            next = move(validator);
    }

    bool shouldBeHired(const Candidate& candidate)
    {
        if (next == nullptr)
        {
             return validate(candidate);
        }
        return validate(candidate) and next->shouldBeHired(candidate);
    }

protected:
    virtual bool validate(const Candidate& candidate) = 0;

private:
    std::unique_ptr<BetterCandidatesValidator> next;
};