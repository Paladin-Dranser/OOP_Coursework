#include "raceremovescreen.h"

RaceRemoveScreen::RaceRemoveScreen(RaceList* ptrRaceLst) :
    ptrRaceList(ptrRaceLst)
{
    // empty;
}

void RaceRemoveScreen::removeRace()
{
    ptrRaceList->display();

    std::cout << "Калі ласка, увядзіце нума гонкі, якую жадаеце выдаліць: ";
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

    Race* race = ptrRaceList->getVectPtrRaces().at(id-1);
    ptrRaceList->removeRace(race);
}
