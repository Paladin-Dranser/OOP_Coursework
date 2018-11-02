#include <iomanip>

#include "contestantlist.h"
#include "../function.h"


ContestantList::ContestantList()
{
    // empty;
}

ContestantList::~ContestantList()
{
    while ( !setPtrContestants.empty() )
    {
        auto iter = setPtrContestants.begin();
        delete *iter;
        setPtrContestants.erase(iter);
    }
}


void ContestantList::display() const
{
    if (setPtrContestants.empty())
    {
        //std::cout << "***No contestants***\n";
        std::cout << "*** Няма спаборнікаў ***\n";
    }
    else
    {
        unsigned count = 1;
        for (Contestant* contestant : setPtrContestants)
        {

            std::cout << std::setw(4) << count << '\t' << *contestant;
            ++count;
        }
    }
}

void ContestantList::insertContestant(Contestant* ptrCont)
{
    setPtrContestants.insert(ptrCont);
}

void ContestantList::editContestant(Contestant* cont)
{
    std::string name;
    //std::cout << "Enter new contestant's name: ";
    std::cout << "Калі ласка, увядзіце новае імя спаборніка: ";
    getLine(name);
    cont->setName(name);

    std::string country;
    //std::cout << "Enter new contestant's name: ";
    std::cout << "Калі ласка, увядзіце новую краіну спаборніка: ";
    getLine(country);
    cont->setCountry(country);
}

void ContestantList::removeContestant(Contestant* cont)
{
    auto iter = setPtrContestants.find(cont);

    delete cont;
    setPtrContestants.erase(iter);
}

std::set<Contestant *, CompareContestants> &ContestantList::getSetPtrContestants()
{
    return setPtrContestants;
}


void ContestantList::readFromFile()
{
    std::ifstream infile;
    infile.open("../contestants.dat", std::ios::binary);

    if (!infile.is_open())
    {
        //std::cout << "Error! DataBase doesn't exist!\n";
        std::cout << "Памылка! База даных не існуе!\n";
    }
    else
    {
        if (infile.eof())
        {
            return;
        }
        unsigned numberOfContestant;
        infile.read(reinterpret_cast<char*>(&numberOfContestant), sizeof(numberOfContestant));

        for (unsigned i = 0; i < numberOfContestant; ++i)
        {
            Contestant* temp = new Contestant();
            temp->readFromFile(infile);
            setPtrContestants.insert(temp);
        }
    }
    infile.close();
}

void ContestantList::writeToFile() const
{
    std::ofstream outfile;
    outfile.open("../contestants.dat", std::ios::binary);
    unsigned numberOfContestant = setPtrContestants.size();
    outfile.write(reinterpret_cast<const char*>(&numberOfContestant), sizeof(numberOfContestant));
    for (auto ptrContestant : setPtrContestants)
    {
        ptrContestant->writeToFile(outfile);
    }
    outfile.close();
}
