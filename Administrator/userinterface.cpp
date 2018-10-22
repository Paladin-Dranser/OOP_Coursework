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
                  << "\t'a' to change users' information;\n"
                  << "\t'i' to input data;\n"
                  << "\t'e' to edit data;\n"
                  << "\t'd' to display data;\n"
                  << "\t'q' to exit;\n";
        ch = getChar();

        if (ch == 'a')
        {
            std::cout << "'d' to display users;\n"
                      << "'a' to add an user;\n"
                      << "'e' to edit an user;\n"
                      << "'r' to remove an user;\n";
            ch = getChar();

            switch (ch)
            {
            case 'd':
                ptrUserList->display();
                break;
            case 'a':
                ptrUserInputScreen = new UserInputScreen(ptrUserList);
                ptrUserInputScreen->getUser();
                delete ptrUserInputScreen;
                break;
            case 'e':
                ptrUserEditScreen = new UserEditScreen(ptrUserList);
                ptrUserEditScreen->editUser();
                delete ptrUserEditScreen;
                break;
            case 'r':
                ptrUserRemoveScreen = new UserRemoveScreen(ptrUserList);
                ptrUserRemoveScreen->removeUser();
                delete ptrUserRemoveScreen;
                break;
            default:
                std::cout << "Невядомая функцыя!\n";
                std::cout << "Incorrect function!\n";
                break;
            }
        }
        else if (ch == 'i')
        {
            std::cout << "'c' to add a contestant;\n"
                      << "'r' to add a race;\n";
            ch = getChar();

            switch (ch)
            {
            case 'c':
                ptrContestantInputScreen = new ContestantInputScreen(ptrContestantList);
                ptrContestantInputScreen->getContestant();
                delete ptrContestantInputScreen;
                break;
            case 'r':
                ptrRaceInputScreen = new RaceInputScreen(ptrRaceList, ptrContestantList);
                ptrRaceInputScreen->getRace();
                delete ptrRaceInputScreen;
                break;
            default:
                std::cout << "Incorrect function.\n";
                break;
            }
        }
        else if (ch == 'e')
        {
           std::cout << "'c' to edit contestant's data;\n"
                     << "'r' to edit data of race;\n"
                     << "'d' to remove contestant's data or data of race;\n";
           ch = getChar();

           switch (ch)
           {
           case 'c':
               ptrContestantEditScreen = new ContestantEditScreen(ptrContestantList);
               ptrContestantEditScreen->editContestant();
               delete ptrContestantEditScreen;
               break;
           case 'r':
               ptrRaceEditScreen = new RaceEditScreen(ptrRaceList, ptrContestantList);
               ptrRaceEditScreen->editRace();
               delete ptrRaceEditScreen;
                   break;
               case 'd':
                   std::cout << "'c' to remove a contestant;\n"
                             << "'r' to remove a race;\n";
                   ch = getChar();
                   if (ch == 'c')
                   {
                       ptrContestantRemoveScreen = new ContestantRemoveScreen(ptrContestantList, ptrRaceList);
                       ptrContestantRemoveScreen->removeContestant();
                       delete ptrContestantRemoveScreen;
                   }
                   else if (ch == 'r')
                   {
                       ptrRaceRemoveScreen = new RaceRemoveScreen(ptrRaceList);
                       ptrRaceRemoveScreen->removeRace();
                           delete ptrRaceRemoveScreen;
                   }
                   else
                       std::cout << "Incorrect function.\n";
                   break;
               default:
                   std::cout << "Incorrect function.\n";
                   break;
            }
        }
        else if (ch == 'd')
        {
            std::cout << "'t' to display The World Cup Rating Table;\n"
                      << "'c' to display contestants' data;\n"
                      << "'r' to display data of races;\n";
            ch = getChar();

            switch (ch)
            {
            case 't':
                ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);
                ptrRatingTable->display();
                delete ptrRatingTable;
                break;
            case 'c':
                ptrContestantList->display();
                break;
            case 'r':
                ptrRaceList->display();
                break;
            default:
                std::cout << "Incorrect function.\n";
                break;
            }
        }
        else if (ch == 'q')
        {
            ptrContestantList->writeToFile();
            ptrRaceList->writeToFile();

            ptrUserList->writeToFile();
            return;
        }
        else
        {
            std::cout << "Incorrect function.\n";
        }
    }
}
