#include "raceinputscreen.h"
#include "../function.h"


RaceInputScreen::RaceInputScreen(RaceList* ptrRaceLst, ContestantList *ptrContestantLst) :
    ptrRaceList(ptrRaceLst), ptrContestantList(ptrContestantLst)
{
    // empty;
}

void RaceInputScreen::getRace()
{
    std::cout << "Калі ласка, увядзіце тып гонкі: ";
    getLine(type);

    std::cout << "Калі ласка, увядзіце вынікі гонкі:\n";

    Race* ptrRace = new Race(type, ptrContestantList);
    ptrRace->setResult();
    ptrRaceList->insertRace(ptrRace);

    std::cout << "Гонка была паспяхова дабаўлена.\n";
    std::cin.get();
}
