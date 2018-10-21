#include "raceinputscreen.h"
#include "../function.h"


RaceInputScreen::RaceInputScreen(RaceList* ptrRaceLst, ContestantList *ptrContestantLst) :
    ptrRaceList(ptrRaceLst), ptrContestantList(ptrContestantLst)
{
    // empty;
}

void RaceInputScreen::getRace()
{
    std::cout << "Увядзіце тып гонкі: ";
    getLine(type);
    std::cout << "Увядзіце вынікі гонкі:\n";
    Race* ptrRace = new Race(type, ptrContestantList);
    ptrRace->setResult();
    ptrRaceList->insertRace(ptrRace);
    std::cout << "Гонка паспяхова дабаўлена!\n";
}
