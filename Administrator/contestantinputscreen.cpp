#include "contestantinputscreen.h"

#include "../function.h"

ContestantInputScreen::ContestantInputScreen(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // emtpy;
}

void ContestantInputScreen::getContestant()
{
    //std::cout << "Enter contestant's name: ";
    std::cout << "Калі ласка, увядзіце імя спаборніка: ";
    getLine(name);
    //std::cout << "Enter contestant's country: ";
    std::cout << "Калі ласка, увядзіце краіну спаборніка: ";
    getLine(country);

    Contestant* ptrContestant = new Contestant(name, country);
    ptrContestantList->insertContestant(ptrContestant);

    //std::cout << "Contestant is added.\n";
    std::cout << "Спаборнік " << name << " з краіны " << country << " паспяхова дабаўлены.\n";
}
