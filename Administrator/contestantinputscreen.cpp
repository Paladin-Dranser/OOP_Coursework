#include "contestantinputscreen.h"

#include "../function.h"

ContestantInputScreen::ContestantInputScreen(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // emtpy;
}

void ContestantInputScreen::getContestant()
{
    std::cout << "Увядзіце імя спаборніка: ";
    getLine(name);
    std::cout << "Увядзіце краіну спаборніка: ";
    getLine(country);

    Contestant* ptrContestant = new Contestant(name, country);
    ptrContestantList->insertContestant(ptrContestant);

    std::cout << "Спаборнік паспяхова дабаўлены!\n";
}
