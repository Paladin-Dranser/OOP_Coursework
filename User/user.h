#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>

class User
{
public:
    User();
    User(std::string l, std::string p);

    void readFromFile(std::istream& in);

    friend bool operator<(const User&, const User&);
    friend bool operator==(const User&, const User&);
private:
    std::string login;
    std::string password;
};

#endif // USER_H
