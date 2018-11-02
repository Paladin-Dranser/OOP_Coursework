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

//    std::cout << "Enter contestant's id to edit his date: ";
    std::cout << "Калі ласка, увядзіце нумар спаборніка, звесткі пра каторага будуць змяняцца: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrContestantList->getSetPtrContestants().begin();
    std::advance(iter, id - 1);

    ptrContestantList->editContestant(*iter);
    //std::cout << "Contestant's data is edited.\n";
    std::cout << "Звесткі спаборніка паспяхова змененыя.\n";
}
