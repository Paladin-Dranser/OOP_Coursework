#include <iostream>

#include "userinputscreen.h"
#include "../function.h"

UserInputScreen::UserInputScreen(UserList *ptrUserLst) :
    ptrUserList(ptrUserLst)
{
    // empty;
}


void UserInputScreen::getUser()
{
    std::cout << "Enter an user's login: ";
    getLine(login);
    std::cout << "Enter an user's password: ";
    getLine(password);

    User* ptrUser = new User(login, password);
    ptrUserList->addUser(ptrUser);

    std::cout << "User is added!\n";
}
