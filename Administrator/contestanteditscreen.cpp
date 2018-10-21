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

    std::cout << "Увядзіце нумар спаборніка, даныя каторага будуць рэдагавацца: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrContestantList->getSetPtrContestants().begin();
    std::advance(iter, id - 1);

    ptrContestantList->editContestant(*iter);
    std::cout << "Даныя спаборніка былі паспяхова адрэдагаваныя.\n";
}
