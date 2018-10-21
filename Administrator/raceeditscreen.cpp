#include <iterator>
#include "raceeditscreen.h"
#include "../function.h"

RaceEditScreen::RaceEditScreen(RaceList* ptrRaceLst, ContestantList* ptrContList) :
    ptrRaceList(ptrRaceLst), ptrContestantList(ptrContList)
{
    // empty;
}

void RaceEditScreen::editRace()
{
    ptrRaceList->display();

    std::cout << "Enter id of race to edit its data: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->editRace(iter);
}
