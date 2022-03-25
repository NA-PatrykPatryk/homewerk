#include "Candidate.hpp"
#include "CandidatesValidator.hpp"
#include "BetterCandidatesValidator.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class Application
{
public:
    Application(std::vector<Candidate> candidate)
    : candidates(candidate)
    {}

    void setRequirements(std::unique_ptr<BetterCandidatesValidator> validator)
    {
        if (requirements == nullptr)
            requirements = std::move(validator);
        else
            requirements -> add(std::move(validator));
    }

    std::vector<Candidate> getFilteredCandidates()
    {
        std::vector<Candidate> qualified;
        std::copy_if(candidates.begin(), candidates.end(), std::back_inserter(qualified),
                     [this](Candidate c)
                     {
                         return requirements->shouldBeHired(c);
                     });
        return qualified;
    }
    
private:
    std::vector<Candidate> candidates;
    std::unique_ptr<BetterCandidatesValidator> requirements;
};
