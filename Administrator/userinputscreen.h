#ifndef USERINPUTSCREEN_H
#define USERINPUTSCREEN_H

#include "userlist.h"

class UserInputScreen
{
public:
    UserInputScreen(UserList* ptrUserLst);
    void getUser();
private:
    UserList* ptrUserList;
    std::string login;
    std::string password;
};

#endif // USERINPUTSCREEN_H
