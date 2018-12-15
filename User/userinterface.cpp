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
                  << "1) Паказаць інфармацыю;\n"
                  << "2) Пошук інфармацыі;\n"
                  << "3) Выйсці;\n"
                  << "\nКалі ласка, увядзіце нумар аперацыі: ";
        ch = getChar();

        if (ch == '1')
        {
            system("clear");
            std::cout << "1) Паказаць табліцу рэйтынгу Кубку Свету;\n"
                      << "2) Сартыраваць табліцу рэйтынгу Кубку Свету паводле імёнаў;\n"
                      << "3) Сартыраваць табліцу рэйтынгу Кубку Свету паводле балаў;\n"
                      << "4) Вярнуцца назад;"
                      << "\nКалі ласка, увядзіце нумар аперацыі: ";
            ch = getChar();

            ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);

            switch (ch)
            {
            case '1':
                system("clear");
                ptrRatingTable->display();
                std::cin.get();
                break;
            case '2':
                system("clear");
                ptrRatingTable->sortByAlphabetical();
                ptrRatingTable->display();
                std::cin.get();
                break;
            case '3':
                system("clear");
                ptrRatingTable->sortByPoints();
                ptrRatingTable->display();
                std::cin.get();
                break;
            case '4':
                break;
            default:
                std::cout << "Невядомая функцыя!\n";
                std::cin.get();
                break;
            }

            delete ptrRatingTable;
        }
        else if (ch == '2')
        {
            ptrRatingTable = new RatingTable(ptrContestantList, ptrRaceList);

            ptrContestantSearchScreen = new ContestantSearchScreen(ptrRatingTable);
            ptrContestantSearchScreen->searchContestant();

            delete ptrRatingTable;
        }
        else if (ch == '3')
        {
            return;
        }
        else
        {
            std::cout << "Невядомая функцыя!\n";
        }
    }
}
