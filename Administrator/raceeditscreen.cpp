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

    std::cout << "Калі ласка, увядзіце нумар гонкі, звесткі пра якую будуць рэдагавацца: ";
    unsigned id;
    std::cin >> id;
    if ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        throw("Памылка! Праграма будзе зачыненая! Неабходна ўводзіць толькі лік!");
    }
    std::cin.ignore(80, '\n');

    if (id > ptrRaceList->getVectPtrRaces().size() )
    {
        std::cout << "Уведзены няправільны нумар;\n";
        std::cin.get();
        return;
    }

    auto iter = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->editRace(iter);
}
