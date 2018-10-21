#include "raceinputscreen.h"
#include "../function.h"


RaceInputScreen::RaceInputScreen(RaceList* ptrRaceLst, ContestantList *ptrContestantLst) :
    ptrRaceList(ptrRaceLst), ptrContestantList(ptrContestantLst)
{
    // empty;
}

void RaceInputScreen::getRace()
{
    std::cout << "Enter a type of race: ";
    getLine(type);
    std::cout << "Enter result of race:\n";
    Race* ptrRace = new Race(type, ptrContestantList);
    ptrRace->setResult();
    ptrRaceList->insertRace(ptrRace);
    std::cout << "Race is added!\n";
}
