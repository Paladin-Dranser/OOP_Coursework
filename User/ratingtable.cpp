#include <iomanip>
#include <algorithm>

#include "compareratingrowbyalphabetical.h"
#include "compareratingrowbypoints.h"

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

void RatingTable::sortByAlphabetical()
{
    std::sort(
              vectRatingRows.begin(),
              vectRatingRows.end(),
              CompareRatingRowByAlphabetical()
             );
}

void RatingTable::sortByPoints()
{
    std::sort(
              vectRatingRows.rbegin(),
              vectRatingRows.rend(),
              CompareRatingRowByPoints()
             );
}

void RatingTable::search(std::string& name) const
{
    bool is_find = false;

    for (RatingRow* ptrRow : vectRatingRows)
    {
        if (ptrRow->getName().find(name) == 0 && !is_find)
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

            is_find = true;
        }
        if (ptrRow->getName().find(name) == 0 && is_find)
        {
            ptrRow->display();
            std::cout << "--------------------------------------------------------------------------------\n";
        }
    }
    if (!is_find)
    {
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << name << " не знойдзены.\n";
        std::cout << "--------------------------------------------------------------------------------\n";
    }
    std::cin.get();
}
