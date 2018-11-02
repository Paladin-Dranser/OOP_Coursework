#include <algorithm>
#include <iterator>
#include <iostream>

#include "usereditscreen.h"

UserEditScreen::UserEditScreen(UserList *ptrUserLst) :
    ptrUserList(ptrUserLst)
{
    // empty;
}

void UserEditScreen::editUser()
{
    ptrUserList->display();

    //std::cout << "Enter a number of user which data will be edited: ";
    std::cout << "Калі ласка, увядзіце нумар карыстальніка, звесткі пра якога будуць рэдагавацца: ";
    unsigned id;
    std::cin >> id;
    std::cin.ignore(80, '\n');

    auto iter = ptrUserList->getSetPtrUsers().begin();
    std::advance(iter, id - 1);

    ptrUserList->editUser(*iter);
    //std::cout << "User's data is edited.\n";
    std::cout << "Звесткі пра карыстальніка паспяхова зменены.\n";
}
