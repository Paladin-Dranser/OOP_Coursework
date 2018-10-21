#include "raceremovescreen.h"

RaceRemoveScreen::RaceRemoveScreen(RaceList* ptrRaceLst) :
    ptrRaceList(ptrRaceLst)
{
    // empty;
}

void RaceRemoveScreen::removeRace()
{
    ptrRaceList->display();

    std::cout << "Увядзіце нумар гонкі на выдаленне: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    Race* race = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->removeRace(race);
}
