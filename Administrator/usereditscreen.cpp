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

    std::cout << "Калі ласка, увядзіце нумар карыстальніка, звесткі пра якога будуць рэдагавацца: ";
    unsigned id;
    std::cin >> id;
    if ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        throw("Памылка! Праграма будзе зачыненая! Неабходна ўводзіць толькі лік!");
    }
    std::cin.ignore(80, '\n');

    if (id > ptrUserList->getSetPtrUsers().size() )
    {
        std::cout << "Уведзены няправільны нумар;\n";
        std::cin.get();
        return;
    }

    auto iter = ptrUserList->getSetPtrUsers().begin();
    std::advance(iter, id - 1);

    ptrUserList->editUser(*iter);
    std::cout << "Звесткі пра карыстальніка паспяхова зменены.\n";
}
