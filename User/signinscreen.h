#ifndef SIGNINSCREEN_H
#define SIGNINSCREEN_H

#include <string>

#include "userlist.h"

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
    UserList* ptrUserList;
    UserInterface* ptrUserInterface;
};

#endif // SIGNINSCREEN_H
