#include "raceinputscreen.h"
#include "../function.h"


RaceInputScreen::RaceInputScreen(RaceList* ptrRaceLst, ContestantList *ptrContestantLst) :
    ptrRaceList(ptrRaceLst), ptrContestantList(ptrContestantLst)
{
    // empty;
}

void RaceInputScreen::getRace()
{
    //std::cout << "Enter a type of race: ";
    std::cout << "Калі ласка, увядзіце тып гонкі: ";
    getLine(type);
    //std::cout << "Enter result of race:\n";
    std::cout << "Калі ласка, увядзіце вынікі гонкі:\n";
    Race* ptrRace = new Race(type, ptrContestantList);
    ptrRace->setResult();
    ptrRaceList->insertRace(ptrRace);
    //std::cout << "Race is added!\n";
    std::cout << "Гонка была паспяхова дабаўлена.\n";
}
