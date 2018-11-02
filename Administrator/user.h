#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>

class User
{
public:
    User();
    User(std::string l, std::string p);

    void display() const;
    void readFromFile(std::istream& in);
    void writeToFile(std::ostream& out) const;

    void setLogin(std::string);
    void setPassword(std::string);

    friend bool operator<(const User&, const User&);
    friend bool operator==(const User&, const User&);
private:
    std::string login;
    std::string password;
};

#endif // USER_H
