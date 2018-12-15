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
    std::cout << "Калі ласка, увядзіце імя спаборніка для пошуку: ";
    std::string name;
    getLine(name);

    ptrRatingTable->search(name);
}
