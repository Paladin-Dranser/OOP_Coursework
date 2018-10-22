#ifndef CONTESTANTSEARCHSCREEN_H
#define CONTESTANTSEARCHSCREEN_H

#include "ratingtable.h"

class ContestantSearchScreen
{
public:
    ContestantSearchScreen(RatingTable* ptrRatingTbl);
    void searchContestant();
private:
    RatingTable* ptrRatingTable;
};

#endif // CONTESTANTSEARCHSCREEN_H
