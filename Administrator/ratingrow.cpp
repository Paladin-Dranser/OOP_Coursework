#include <iomanip>

#include "ratingrow.h"

RatingRow::RatingRow(Contestant *ptrCont, RaceList *ptrRaceLst) :
    ptrContestant(ptrCont), ptrRaceList(ptrRaceLst)
{
    for (Race* race : ptrRaceLst->getVectPtrRaces())
    {
        unsigned temp = race->getContestantPoints(ptrCont);
        vectPointsForRaces.push_back(temp);
    }
}

void RatingRow::display() const
{
    unsigned all_points = 0;
    std::cout << std::setw(15 + ptrContestant->getName().length() / 2) << ptrContestant->getName();
    for (unsigned points : vectPointsForRaces)
    {
        std::cout << std::setw(15) << points;
        all_points += points;
    }
    std::cout << std::setw(15) << all_points << std::endl;
}
