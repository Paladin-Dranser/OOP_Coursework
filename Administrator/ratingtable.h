#ifndef RATINGTABLE_H
#define RATINGTABLE_H

#include <vector>

#include "ratingrow.h"
#include "contestantlist.h"
#include "racelist.h"

class RatingTable
{
public:
    RatingTable(ContestantList* ptrContenstantList, RaceList* ptrRaceLst);
    ~RatingTable();
    void display() const;
private:
    RaceList* ptrRaceList;
    std::vector<RatingRow*> vectRatingRows;
};

#endif // RATINGTABLE_H
