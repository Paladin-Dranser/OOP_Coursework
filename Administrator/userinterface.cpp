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
}

void UserInterface::interact()
{
    ptrContestantList->readFromFile();
    ptrRaceList->readFromFile();

    ptrUserList->readFromFile();

    while (true)
    {
        std::cout << "Kалі ласка, націсніце клавішу:\n"
                  << "\t'a' для кіравання карыстальнікаў;\n\n"
                  << "\t'i' для ўводу даных;\n"
                  << "\t'e' для рэдагавання даных;\n"
                  << "\t'd' для прагляду рэйтынгу;\n"
                  << "\t'q' для выхаду;\n";
        ch = getChar();

        if (ch == 'a')
        {
            std::cout << "'d' to display users;\n"
                      << "'a' для дабаўлення карыстальніка;\n"
                      << "'e' для рэдагавання карыстальніка;\n"
                      << "'r' для выдалення карыстальніка;\n";
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
                break;
            }
        }
        else if (ch == 'i')
        {
            std::cout << "'c' для дабаўлення спаборніка;\n";
            std::cout << "'r' для дабаўлення гонкі;\n";
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
                std::cout << "Невядомая фунцыя.\n";
                break;
            }
        }
        else if (ch == 'e')
        {
           std::cout << "'c' для рэдагавання даных спаборніка;\n"
                     << "'r' для рэдагавання даных пра гонку;\n"
                     << "'d' для выдалення даных;\n";
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
                   std::cout << "'c' для выдалення спаборніка;\n"
                             << "'r' для выдалення гонкі;\n";
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
                           std::cout << "Невядомая функцыя.\n";
                       break;
                   default:
                       std::cout << "Невядомая фунцыя.\n";
                       break;
            }
        }
        else if (ch == 'd')
        {
            std::cout << "'t' для вываду агульнага рэйтынгу Кубка Свету;\n"
                      << "'c' для вываду інфармацыі пра спаборнікаў;\n"
                      << "'r' для вываду інфармацыі пра гонкі;\n";
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
                std::cout << "Невядомая фунцыя.\n";
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
            std::cout << "Невядомая функцыя. Націскайце толькі 'i', 'd', 'q'!\n";
    }
}
