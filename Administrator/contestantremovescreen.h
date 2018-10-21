#ifndef CONTESTANTREMOVESCREEN_H
#define CONTESTANTREMOVESCREEN_H

#include "contestantlist.h"
#include "racelist.h"

class ContestantRemoveScreen
{
public:
    ContestantRemoveScreen(ContestantList* ptrContList, RaceList* ptrRaceLst);
    void removeContestant();
private:
    ContestantList* ptrContestantList;
    RaceList* ptrRaceList;
};

#endif // CONTESTANTREMOVESCREEN_H
