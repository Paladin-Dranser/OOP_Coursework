#include <iostream>
#include <string>

#include "contestantsearchscreen.h"

#include "../function.h"

ContestantSearchScreen::ContestantSearchScreen(RatingTable *ptrRatingTbl) :
    ptrRatingTable(ptrRatingTbl)
{
    // empty;
}

void ContestantSearchScreen::searchContestant()
{
    std::cout << "Enter contestant's name to find him: ";
    std::string name;
    getLine(name);

    ptrRatingTable->search(name);
}
