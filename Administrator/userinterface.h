#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "ratingtable.h"

#include "contestantlist.h"
#include "contestantinputscreen.h"
#include "contestanteditscreen.h"
#include "contestantremovescreen.h"

#include "racelist.h"
#include "raceinputscreen.h"
#include "raceeditscreen.h"
#include "raceremovescreen.h"

#include "userlist.h"
#include "userinputscreen.h"
#include "usereditscreen.h"
#include "userremovescreen.h"

class UserInterface
{
public:
    UserInterface();
    ~UserInterface();
    void interact();
private:
    RatingTable* ptrRatingTable;

    ContestantList* ptrContestantList;
    ContestantInputScreen* ptrContestantInputScreen;
    ContestantEditScreen* ptrContestantEditScreen;
    ContestantRemoveScreen* ptrContestantRemoveScreen;

    RaceList* ptrRaceList;
    RaceInputScreen* ptrRaceInputScreen;
    RaceEditScreen* ptrRaceEditScreen;
    RaceRemoveScreen* ptrRaceRemoveScreen;

    UserList* ptrUserList;
    UserInputScreen* ptrUserInputScreen;
    UserEditScreen* ptrUserEditScreen;
    UserRemoveScreen* ptrUserRemoveScreen;

    char ch;
};

#endif // USERINTERFACE_H
