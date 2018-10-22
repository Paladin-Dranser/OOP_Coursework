#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "ratingtable.h"
#include "contestantlist.h"
#include "racelist.h"
#include "userlist.h"

#include "contestantsearchscreen.h"

class UserInterface
{
public:
    UserInterface();
    ~UserInterface();
    void interact();
private:
    RatingTable* ptrRatingTable;
    ContestantList* ptrContestantList;
    RaceList* ptrRaceList;
    UserList* ptrUserList;

    ContestantSearchScreen* ptrContestantSearchScreen;

    char ch;
};

#endif // USERINTERFACE_H
