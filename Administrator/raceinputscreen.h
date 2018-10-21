#ifndef RACEINPUTSCREEN_H
#define RACEINPUTSCREEN_H

#include <iostream>

#include "racelist.h"
#include "contestantlist.h" // for result

class RaceInputScreen
{
public:
    RaceInputScreen(RaceList* ptrRaceLst, ContestantList* ptrContestantLst);
    void getRace();
private:
    RaceList* ptrRaceList;
    ContestantList* ptrContestantList;
    std::string type;
};

#endif // RACEINPUTSCREEN_H
