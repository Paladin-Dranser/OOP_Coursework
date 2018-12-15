#include "signinscreen.h"

#include <iostream>

#include "../function.h"

SignInScreen::SignInScreen() :
    login(""), password("")
{
    // empty;
}

SignInScreen::~SignInScreen()
{
    delete ptrUserInterface;
}

bool SignInScreen::signIn() const
{
    User temp(login, password);

    for (User* ptrUser : ptrUserList->getSetPtrUsers())
    {
        if (temp == *ptrUser)
        {
            return true;
        }
    }

    return false;
}

void SignInScreen::interact()
{
    ptrUserList = new UserList;
    ptrUserList->readFromFile();

    while (true)
    {
        std::cout << "-------------------- Уваход --------------------\n";
        std::cout << "Логін: ";
        getLine(login);
        std::cout << "Пароль: ";
        getLine(password);

        if ( signIn() )
        {
            std::cout << "-----------------------------------------------\n";
            delete ptrUserList;

            ptrUserInterface = new UserInterface();
            ptrUserInterface->interact();

            return;
        }
        else
        {
            std::cout << "Няправільны логін або пароль.\n";
        }
    }
}
