#include "userlist.h"

#include <iostream>
#include <iterator>

#include "../function.h"

UserList::UserList()
{
    // empty;
}

UserList::~UserList()
{
    while ( !setPtrUsers.empty() )
    {
        auto iter = setPtrUsers.begin();
        delete *iter;
        setPtrUsers.erase(iter);
    }
}

void UserList::display() const
{
    unsigned count = 1;
    for (User* ptrUser : setPtrUsers)
    {
        std::cout << count << '\t';
        ptrUser->display();
        ++count;
    }
}

void UserList::addUser(User* ptrUser)
{
    setPtrUsers.insert(ptrUser);
}

void UserList::editUser(User* ptrUser)
{
    std::cout << "Калі ласка, увядзіце новае імя карыстальніка: ";
    std::string login;
    getLine(login);
    ptrUser->setLogin(login);

    std::cout << "Калі ласка, увядзіце новы пароль: ";
    std::string password;
    getLine(password);
    ptrUser->setPassword(password);
}

void UserList::removeUser(User * ptrUser)
{
    auto iter = setPtrUsers.find(ptrUser);

    delete ptrUser;
    setPtrUsers.erase(iter);
}

std::set<User*, CompareUsers>& UserList::getSetPtrUsers()
{
    return setPtrUsers;
}

void UserList::readFromFile()
{
    std::ifstream infile;
    infile.open("../users.dat", std::ios::binary);

    if (!infile.is_open())
    {
        std::cout << "Памылка! Базы даных карыстальнікаў не існуе!\n";
    }
    else
    {
        if (infile.eof())
        {
            return;
        }
        unsigned numberOfUser;
        infile.read(reinterpret_cast<char*>(&numberOfUser), sizeof(numberOfUser));

        for (unsigned i = 0; i < numberOfUser; ++i)
        {
            User* temp = new User();
            temp->readFromFile(infile);
            setPtrUsers.insert(temp);
        }
    }
    infile.close();
}

void UserList::writeToFile() const
{
    std::ofstream outfile;
    outfile.open("../users.dat", std::ios::binary);
    unsigned numberOfUser = setPtrUsers.size();
    outfile.write(reinterpret_cast<const char*>(&numberOfUser), sizeof(numberOfUser));
    for (auto ptrUser : setPtrUsers)
    {
        ptrUser->writeToFile(outfile);
    }
    outfile.close();
}
