#ifndef RACEREMOVESCREEN_H
#define RACEREMOVESCREEN_H

#include "racelist.h"

class RaceRemoveScreen
{
public:
    RaceRemoveScreen(RaceList* ptrRaceLst);
    void removeRace();
private:
    RaceList* ptrRaceList;
};

#endif // RACEREMOVESCREEN_H
