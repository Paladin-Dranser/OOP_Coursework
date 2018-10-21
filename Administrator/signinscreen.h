#ifndef SIGNINSCREEN_H
#define SIGNINSCREEN_H

#include <string>

#include "userinterface.h"

class SignInScreen
{
public:
    SignInScreen();
    ~SignInScreen();
    bool signIn() const;
    void interact();
private:
    std::string login;
    std::string password;
    UserInterface* ptrUserInterface;
};

#endif // SIGNINSCREEN_H
