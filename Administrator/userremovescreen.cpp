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

    std::cout << "Калі ласка, увядзіце нумар карыстальніка, які будзе выдалены: ";
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

    ptrUserList->removeUser(*iter);

    std::cout << "Карыстальнік паспяхова выдалены.\n";
}
