#ifndef RACELIST_H
#define RACELIST_H

#include "race.h"
#include "contestantlist.h"

class RaceList
{
public:
    RaceList(ContestantList* ptrContList);
    ~RaceList();
    void display() const;
    std::vector<Race*> & getVectPtrRaces();

    void readFromFile();
private:
    ContestantList* ptrContestantList;
    std::vector<Race*> vectPtrRaces;

};

#endif // RACELIST_H
