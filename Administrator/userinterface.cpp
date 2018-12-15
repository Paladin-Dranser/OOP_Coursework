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
        system("clear");
        std::cout << "Калі ласка, абярыце адну з наступных аперацый:\n"
                  << "1) Змена інфармацыі пра карыстальніка;\n"
                  << "2) Увод новай інфармацыі (спаборніка альбо гонкі);\n"
                  << "3) Рэдагаванне інфармацыі (спаборніка альбо гонкі);\n"
                  << "4) Паказаць інфармацыю;\n"
                  << "5) Выйсці;\n"
                  << "\nКалі ласка, увядзіце нумар аперацыі: ";
        ch = getChar();

        if (ch == '1')
        {
            system("clear");
            std::cout << "Калі ласка, выбярыце аперацыю:\n"
                      << "1) Паказаць інфармацыю карыстальнікаў;\n"
                      << "2) Дабавіць новага карыстальніка;\n"
                      << "3) Рэдагаваць інфармацыю пра карыстальніка;\n"
                      << "4) Выдаленне карыстальніка;\n"
                      << "5) Вярнуцца назад;\n"
                      << "\nКалі ласка, увядзіце нумар аперацыі: ";
            ch = getChar();

            switch (ch)
            {
            case '1':
                system("clear");
                ptrUserList->display();
                std::cin.get();
                break;
            case '2':
                ptrUserInputScreen = new UserInputScreen(ptrUserList);
                ptrUserInputScreen->getUser();
                delete ptrUserInputScreen;
                ptrUserList->writeToFile();
                break;
            case '3':
                ptrUserEditScreen = new UserEditScreen(ptrUserList);
                ptrUserEditScreen->editUser();
                delete ptrUserEditScreen;
                ptrUserList->writeToFile();
                break;
            case '4':
                ptrUserRemoveScreen = new UserRemoveScreen(ptrUserList);
                ptrUserRemoveScreen->removeUser();
                delete ptrUserRemoveScreen;
                ptrUserList->writeToFile();
                break;
            case '5':
                break;
            default:
                std::cout << "Невядомая функцыя!\n";
                break;
            }
        }
        else if (ch == '2')
        {
            system("clear");
            std::cout << "1) Дабавіць новага спаборніка;\n"
                      << "2) Дабавіць новую гонку;\n"
                      << "3) Вярнуцца назад;\n"
                      << "\nКалі ласка, увядзіце нумар аперацыі: ";
            ch = getChar();

            switch (ch)
            {
            case '1':
                ptrContestantInputScreen = new ContestantInputScreen(ptrContestantList);
                ptrContestantInputScreen->getContestant();
                delete ptrContestantInputScreen;
                ptrContestantList->writeToFile();
                break;
            case '2':
                ptrRaceInputScreen = new RaceInputScreen(ptrRaceList, ptrContestantList);
                ptrRaceInputScreen->getRace();
                delete ptrRaceInputScreen;
                ptrRaceList->writeToFile();
                break;
            case '3':
                break;
            default:
                std::cout << "Выбрана невядомая аперацыя.\n";
                break;
            }
        }
        else if (ch == '3')
        {
            system("clear");
            std::cout << "1) Рэдагаваць інфармацыю пра ўдзельніка;\n"
                      << "2) Рэдагаваць інфармацыю пра гонку;\n"
                      << "3) Выдаліць інфармацыю пра спаборніка;\n"
                      << "4) Выдаліць інфармацыю пра гонку;\n"
                      << "5) Вярнуцца назад;\n"
                      << "\nКалі ласка, увядзіце нумар аперацыі: ";
            ch = getChar();

            switch (ch)
            {
            case '1':
                ptrContestantEditScreen = new ContestantEditScreen(ptrContestantList);
                ptrContestantEditScreen->editContestant();
                delete ptrContestantEditScreen;
                ptrContestantList->writeToFile();
                break;
            case '2':
                ptrRaceEditScreen = new RaceEditScreen(ptrRaceList, ptrContestantList);
                ptrRaceEditScreen->editRace();
                delete ptrRaceEditScreen;
                ptrRaceList->writeToFile();
                break;
            case '3':
                ptrContestantRemoveScreen = new ContestantRemoveScreen(ptrContestantList, ptrRaceList);
                ptrContestantRemoveScreen->removeContestant();
                delete ptrContestantRemoveScreen;
                ptrContestantList->writeToFile();
                break;
            case '4':
                ptrRaceRemoveScreen = new RaceRemoveScreen(ptrRaceList);
                ptrRaceRemoveScreen->removeRace();
                delete ptrRaceRemoveScreen;
                ptrRaceList->writeToFile();
                break;
            case '5':
                break;
            default:
                std::cout << "Выбрана невядомая аперацыя.\n";
                break;
            }
        }
        else if (ch == '4')
        {
            system("clear");
            std::cout << "1) Паказаць рэйтынг Кубку Свету;\n"
                      << "2) Паказаць інфармацыю па спаборніках;\n"
                      << "3) Паказаць інфармацыю па гонках;\n"
                      << "4) Вярнуцца назад;\n"
                      << "\nКалі ласка, увядзіце нумар аперацыі: ";
            ch = getChar();

            switch (ch)
            {
            case '1':
                system("clear");
                ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);
                ptrRatingTable->display();
                delete ptrRatingTable;
                std::cin.get();
                break;
            case '2':
                system("clear");
                ptrContestantList->display();
                std::cin.get();
                break;
            case '3':
                system("clear");
                ptrRaceList->display();
                std::cin.get();
                break;
            case '4':
                break;
            default:
                std::cout << "Выбрана невядомая аперацыя.\n";
                std::cin.get();
                break;
            }
        }
        else if (ch == '5')
        {
            ptrContestantList->writeToFile();
            ptrRaceList->writeToFile();

            ptrUserList->writeToFile();
            return;
        }
        else
        {
            std::cout << "Выбрана невядомая аперацыя.\n";
            std::cin.get();
        }
    }
}
