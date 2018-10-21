#ifndef USERREMOVESCREEN_H
#define USERREMOVESCREEN_H

#include "userlist.h"

class UserRemoveScreen
{
public:
    UserRemoveScreen(UserList* ptrUserLst);
    void removeUser();
private:
    UserList* ptrUserList;
};

#endif // USERREMOVESCREEN_H
