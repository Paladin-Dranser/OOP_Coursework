#include <algorithm>
#include <iterator>

#include "contestantremovescreen.h"
#include "../function.h"

ContestantRemoveScreen::ContestantRemoveScreen(ContestantList *ptrContList, RaceList* ptrRaceLst) :
    ptrContestantList(ptrContList), ptrRaceList(ptrRaceLst)
{
    // empty;
}

void ContestantRemoveScreen::removeContestant()
{
    ptrContestantList->display();

    std::cout << "Калі ласка, увядзіце нумар спаборніка, якога жадаеце выдаліць: ";
    unsigned id;
    std::cin >> id;
    if ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        throw("Памылка! Праграма будзе зачыненая! Неабходна ўводзіць толькі лік!");
    }
    std::cin.ignore(80, '\n');

    if (id > ptrContestantList->getSetPtrContestants().size() )
    {
        std::cout << "Уведзены няправільны нумар;\n";
        std::cin.get();
        return;
    }

    auto iter = ptrContestantList->getSetPtrContestants().begin();
    std::advance(iter, id - 1);

    ptrRaceList->removeContestantResult(*iter);
    ptrContestantList->removeContestant(*iter);

    std::cout << "Спаборнік быў паспяхова выдалены!\n";
    std::cin.get();
}
