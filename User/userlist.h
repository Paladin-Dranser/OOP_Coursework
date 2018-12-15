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

    std::set<User*, CompareUsers> & getSetPtrUsers();
    void readFromFile();
private:
    std::set<User*, CompareUsers> setPtrUsers;

};

#endif // USERLIST_H
