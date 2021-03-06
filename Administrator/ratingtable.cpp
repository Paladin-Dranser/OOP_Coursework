#include <iomanip>

#include "ratingtable.h"

RatingTable::RatingTable(ContestantList* ptrContenstantList, RaceList* ptrRaceLst) :
    ptrRaceList(ptrRaceLst)
{
    for (Contestant* contestant : ptrContenstantList->getSetPtrContestants())
    {
        RatingRow* temp = new RatingRow(contestant, ptrRaceList);
        vectRatingRows.push_back(temp);
    }
}

RatingTable::~RatingTable()
{
    for (RatingRow* row: vectRatingRows)
    {
        delete row;
    }
    vectRatingRows.clear();
}

void RatingTable::display() const
{
    std::cout << "\n================================================================================\n";
    std::cout << std::setw(15 + 9) << "Спаборнік";
    for ( Race* race : ptrRaceList->getVectPtrRaces() )
    {
        std::string temp = race->getType();
        std::cout << std::setw(15 + temp.length() / 2) << temp;
    }
    std::cout << std::setw(15 + 4) << "Балы" << std::endl;

    std::cout << "================================================================================\n";

    for (RatingRow* row : vectRatingRows)
    {
        row->display();
        std::cout << "--------------------------------------------------------------------------------\n";
    }
    std::cout << std::endl;
}
