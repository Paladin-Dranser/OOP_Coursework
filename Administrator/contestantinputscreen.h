#ifndef CONTESTANTINPUTSCREEN_H
#define CONTESTANTINPUTSCREEN_H

#include <string>

#include "contestantlist.h"

class ContestantInputScreen
{
public:
    ContestantInputScreen(ContestantList* ptrContList);
    void getContestant();
private:
    ContestantList* ptrContestantList;
    std::string name;
    std::string country;
};

#endif // CONTESTANTINPUTSCREEN_H
