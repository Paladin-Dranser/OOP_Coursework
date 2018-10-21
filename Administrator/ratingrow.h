#ifndef RATINGROW_H
#define RATINGROW_H

#include <iostream>
#include <vector>

#include "contestant.h"
#include "racelist.h"

class RatingRow
{
public:
    RatingRow(Contestant* ptrCont, RaceList* ptrRaceLst);
    void display() const;
private:
    Contestant* ptrContestant;
    RaceList* ptrRaceList;
    std::vector<unsigned> vectPointsForRaces;
};

#endif // RATINGROW_H
