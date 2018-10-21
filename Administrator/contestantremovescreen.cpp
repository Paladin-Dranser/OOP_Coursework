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

    std::cout << "Enter contestant's id to remove him: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrContestantList->getSetPtrContestants().begin();
    std::advance(iter, id - 1);

    ptrRaceList->removeContestantResult(*iter);
    ptrContestantList->removeContestant(*iter);
}
