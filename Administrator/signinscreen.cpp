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
    return (login == "Admin") && (password == "Admin");
}

void SignInScreen::interact()
{
    while (true)
    {
        std::cout << "--------------------Sign in--------------------\n";
        std::cout << "Login: ";
        getLine(login);
        std::cout << "Password: ";
        getLine(password);

        if ( signIn() )
        {
            ptrUserInterface = new UserInterface();
            ptrUserInterface->interact();
            return;
        }
        else
        {
            std::cout << "Вы ўвялі няправільныя логін і пароль.\n";
        }
    }
}
