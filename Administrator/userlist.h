#ifndef USERLIST_H
#define USERLIST_H

#include <set>

#include "user.h"
#include "compareusers.h"

class UserList
{
public:
    UserList();
    ~UserList();

    void display() const;
    void addUser(User*);
    void editUser(User*);
    void removeUser(User*);
    std::set<User*, CompareUsers> & getSetPtrUsers();

    void readFromFile();
    void writeToFile() const;
private:
    std::set<User*, CompareUsers> setPtrUsers;

};

#endif // USERLIST_H
