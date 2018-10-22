#include <iostream>

#include "user.h"

User::User() :
    login(""), password("")
{
    // empty;
}

User::User(std::string l, std::string p) :
    login(l), password(p)
{
    // emtpy;
}

void User::display() const
{
    std::cout << "Login: " << login << "\tPassword: " << password << std::endl;
}

void User::setLogin(std::string l)
{
    login = l;
}

void User::setPassword(std::string p)
{
    password = p;
}

void User::readFromFile(std::istream& in)
{
    unsigned len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    char* buf = new char[len];
    in.read(buf, len);
    login = buf;
    delete[] buf;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buf = new char[len];
    in.read(buf, len);
    password = buf;
    delete[] buf;
}

void User::writeToFile(std::ostream& out)
{
    unsigned len = login.size() + 1;
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reinterpret_cast<const char*>(login.c_str()), len);

    len = password.size() + 1;
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reinterpret_cast<const char*>(password.c_str()), len);
}


bool operator==(const User& user1, const User& user2)
{
    return (user1.login == user2.login) && (user1.password == user2.password);
}

bool operator<(const User& user1, const User& user2)
{
    return user1.login < user2.login;
}
