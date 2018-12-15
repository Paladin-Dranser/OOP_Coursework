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
    std::cout << "Калі ласка, увядзіце імя карыстальніка: ";
    getLine(login);

    std::cout << "Калі ласка, увядзіце пароль карыстальніка: ";
    getLine(password);

    User* ptrUser = new User(login, password);
    ptrUserList->addUser(ptrUser);

    std::cout << "Карыстальнік " << login << " паспяхова дабаўлены.\n";
}
