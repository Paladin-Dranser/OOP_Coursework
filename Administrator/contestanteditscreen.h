#ifndef CONTESTANTEDITSCREEN_H
#define CONTESTANTEDITSCREEN_H

#include <string>

#include "contestantlist.h"

class ContestantEditScreen
{
public:
    ContestantEditScreen(ContestantList* ptrContList);
    void editContestant();
private:
    ContestantList* ptrContestantList;
    std::string name;
    std::string country;
};

#endif // CONTESTANTEDITSCREEN_H
