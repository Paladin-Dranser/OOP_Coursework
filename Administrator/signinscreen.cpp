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
        std::cout << "-------------------- Уваход --------------------\n";
        std::cout << "Імя: ";
        getLine(login);
        std::cout << "Пароль: ";
        getLine(password);

        if ( signIn() )
        {
            std::cout << "-----------------------------------------------\n";
            ptrUserInterface = new UserInterface();

            try
            {
                ptrUserInterface->interact();
            }
            catch (const char* msg)
            {
                std::cout << msg << std::endl;
            }

            return;
        }
        else
        {
            std::cout << "Памылка! Уведзеныя імя і/альбо пароль некарэктныя.\n";
        }
    }
}
