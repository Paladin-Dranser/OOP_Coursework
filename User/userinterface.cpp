#include "userinterface.h"

#include <fstream>

#include "../function.h"

UserInterface::UserInterface()
{
    ptrContestantList = new ContestantList;
    ptrRaceList = new RaceList(ptrContestantList);
    ptrUserList = new UserList;
}

UserInterface::~UserInterface()
{
    delete ptrContestantList;
    delete ptrRaceList;
    delete ptrUserList;
}

void UserInterface::interact()
{
    ptrContestantList->readFromFile();
    ptrRaceList->readFromFile();

    ptrUserList->readFromFile();

    while (true)
    {
        std::cout << "Please, press a key:\n"
                  << "\t'd' to display data;\n"
                  << "\t's' to search data;\n"
                  << "\t'q' to exit;\n";
        ch = getChar();

        if (ch == 'd')
        {
            std::cout << "'d' to display The World Cup Rating Table;\n"
                      << "'a' to sort The World Cup Rating Table by contestant's name;\n"
                      << "'p' to sort The World Cup Rating Table by points;\n";
            ch = getChar();

            ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);

            switch (ch)
            {
            case 'd':
                ptrRatingTable->display();
                break;
            case 'a':
                ptrRatingTable->sortByAlphabetical();
                ptrRatingTable->display();
                break;
            case 'p':
                ptrRatingTable->sortByPoints();
                ptrRatingTable->display();
                break;
            default:
                std::cout << "Incorrect function.\n";
                break;
            }

            delete ptrRatingTable;
        }
        else if (ch == 's')
        {
            ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);

            ptrContestantSearchScreen = new ContestantSearchScreen(ptrRatingTable);
            ptrContestantSearchScreen->searchContestant();

            delete ptrRatingTable;
        }
        else if (ch == 'q')
        {
            return;
        }
        else
        {
            std::cout << "Incorrect function.\n";
        }
    }
}
