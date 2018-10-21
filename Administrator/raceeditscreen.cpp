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

    std::cout << "Увядзіце нумар гонкі, даныя каторай будуць рэдагавацца: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    //std::cout << "Увядзіце новы тып гонкі: ";
    //getLine(type);

    auto iter = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->editRace(iter);
/*
    std::vector<Race*> ptrVectRaces = ptrRaceList->getVectPtrRaces();
    ptrVectRaces.at(id-1)->setType(type);
    ptrVectRaces.at(id-1)->setResult(ptrContestantList);
*/
}
