#include "raceremovescreen.h"

RaceRemoveScreen::RaceRemoveScreen(RaceList* ptrRaceLst) :
    ptrRaceList(ptrRaceLst)
{
    // empty;
}

void RaceRemoveScreen::removeRace()
{
    ptrRaceList->display();

    //std::cout << "Enter an id of race to remove it: ";
    std::cout << "Калі ласка, увядзіце нума гонкі, якую жадаеце выдаліць: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    Race* race = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->removeRace(race);
}
