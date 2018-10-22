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
            std::cout << "-----------------------------------------------\n";
            ptrUserInterface = new UserInterface();
            ptrUserInterface->interact();
            return;
        }
        else
        {
            std::cout << "Wrong login or password.\n";
        }
    }
}
