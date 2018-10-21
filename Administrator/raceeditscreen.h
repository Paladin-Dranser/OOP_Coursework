#ifndef RACEEDITSCREEN_H
#define RACEEDITSCREEN_H

#include <string>
#include <vector>

#include "contestantlist.h"
#include "racelist.h"

class RaceEditScreen
{
public:
    RaceEditScreen(RaceList* ptrRaceLst, ContestantList* ptrContList);
    void editRace();
private:
    RaceList* ptrRaceList;
    ContestantList* ptrContestantList;
    std::string type;
};

#endif // RACEEDITSCREEN_H
