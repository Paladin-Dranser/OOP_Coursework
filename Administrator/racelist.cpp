#include <algorithm>
#include <iterator>
#include <iomanip>

#include "racelist.h"
#include "../function.h"

RaceList::RaceList(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // empty;
}

RaceList::~RaceList()
{
    for (Race* race : vectPtrRaces)
    {
        delete race;
    }
    vectPtrRaces.clear();
}

void RaceList::display() const
{
    if ( vectPtrRaces.empty() )
    {
        std::cout << "*** Няма гонак ***\n";
    }
    else
    {
        unsigned count = 1;
        for (Race* race : vectPtrRaces)
        {
            std::cout << std::setw(4) << count << '\t' << *race;
            ++count;
        }
    }
}

void RaceList::insertRace(Race* ptrRace)
{
    vectPtrRaces.push_back(ptrRace);
}

void RaceList::editRace(Race* race)
{
    std::string type;
    std::cout << "Калі ласка, увядзіце новы тып гонкі: ";
    getLine(type);

    race->setType(type);
    race->setResult();
}

void RaceList::removeRace(Race* race)
{
    auto iter = std::find(
                          vectPtrRaces.begin(),
                          vectPtrRaces.end(),
                          race
                         );
    delete race;

    if ( iter != vectPtrRaces.end() )
    {
        vectPtrRaces.erase(iter);
    }
}

void RaceList::removeContestantResult(Contestant* cont)
{
    for (Race* race : vectPtrRaces)
    {
        race->removeResult(cont);
    }
}

std::vector<Race *> &RaceList::getVectPtrRaces()
{
    return vectPtrRaces;
}

void RaceList::readFromFile()
{
    std::ifstream infile;
    infile.open("../races.dat", std::ios::binary);

    if (!infile.is_open())
    {
        std::cout << "Памылка! База даных гонак не існуе!\n";
    }
    else
    {
        if (infile.eof())
        {
            return;
        }
        unsigned numberOfRaces;
        infile.read(reinterpret_cast<char*>(&numberOfRaces), sizeof(numberOfRaces));

        for (unsigned i = 0; i < numberOfRaces; ++i)
        {
            Race* temp = new Race(ptrContestantList);
            temp->readFromFile(infile);
            vectPtrRaces.push_back(temp);
        }
    }
    infile.close();
}


void RaceList::writeToFile() const
{
    std::ofstream outfile;
    outfile.open("../races.dat", std::ios::binary);
    unsigned numberOfRaces= vectPtrRaces.size();
    outfile.write(reinterpret_cast<const char*>(&numberOfRaces), sizeof(numberOfRaces));
    for (Race* ptrRace : vectPtrRaces)
    {
        ptrRace->writeToFile(outfile);
    }
    outfile.close();
}
