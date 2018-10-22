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
    void insertRace(Race*);
    void editRace(Race*);
    void removeRace(Race*);
    void removeContestantResult(Contestant*);
    std::vector<Race*> & getVectPtrRaces();

    void readFromFile();
    void writeToFile() const;
private:
    ContestantList* ptrContestantList;
    std::vector<Race*> vectPtrRaces;

};

#endif // RACELIST_H
