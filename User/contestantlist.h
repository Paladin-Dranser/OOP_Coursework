#ifndef CONTESTANTLIST_H
#define CONTESTANTLIST_H

#include <fstream>

#include <set>
#include <iterator>

#include "contestant.h"
#include "comparecontestants.h"

class ContestantList
{
public:
    ContestantList();
    ~ContestantList();
    void display() const;
    std::set<Contestant*, CompareContestants> & getSetPtrContestants();

    void readFromFile();
private:
    std::set<Contestant*, CompareContestants> setPtrContestants;
};

#endif // CONTESTANTLIST_H
