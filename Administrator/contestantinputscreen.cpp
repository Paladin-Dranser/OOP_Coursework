#include "contestantinputscreen.h"

#include "../function.h"

ContestantInputScreen::ContestantInputScreen(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // emtpy;
}

void ContestantInputScreen::getContestant()
{
    std::cout << "Enter contestant's name: ";
    getLine(name);
    std::cout << "Enter contestant's country: ";
    getLine(country);

    Contestant* ptrContestant = new Contestant(name, country);
    ptrContestantList->insertContestant(ptrContestant);

    std::cout << "Contestant is added.\n";
}
