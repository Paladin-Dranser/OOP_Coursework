#include <iostream>

#include "userremovescreen.h"

UserRemoveScreen::UserRemoveScreen(UserList *ptrUserLst) :
    ptrUserList(ptrUserLst)
{
    // empty;
}

void UserRemoveScreen::removeUser()
{
    ptrUserList->display();

    std::cout << "Enter user's id to remove him: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrUserList->getSetPtrUsers().begin();
    std::advance(iter, id - 1);

    ptrUserList->removeUser(*iter);

    std::cout << "User is removed.\n";
}
