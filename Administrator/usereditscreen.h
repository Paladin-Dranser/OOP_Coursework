#ifndef USEREDITSCREEN_H
#define USEREDITSCREEN_H

#include "userlist.h"

class UserEditScreen
{
public:
    UserEditScreen(UserList* ptrUserLst);
    void editUser();
private:
    UserList* ptrUserList;
};

#endif // USEREDITSCREEN_H
