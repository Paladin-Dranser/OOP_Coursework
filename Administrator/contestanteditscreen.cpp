#include <algorithm>
#include <iterator>

#include "contestanteditscreen.h"
#include "../function.h"

ContestantEditScreen::ContestantEditScreen(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // empty;
}

void ContestantEditScreen::editContestant()
{
    ptrContestantList->display();

    std::cout << "Калі ласка, увядзіце нумар спаборніка, звесткі пра каторага будуць змяняцца: ";
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

    ptrContestantList->editContestant(*iter);
    //std::cout << "Contestant's data is edited.\n";
    std::cout << "Звесткі спаборніка паспяхова змененыя.\n";
}
