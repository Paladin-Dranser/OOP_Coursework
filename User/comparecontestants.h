#ifndef COMPARECONTESTANTS_H
#define COMPARECONTESTANTS_H

#include "contestant.h"

class CompareContestants
{
public:
    bool operator()(const Contestant*, const Contestant*) const;
};

#endif // COMPARECONTESTANTS_H
