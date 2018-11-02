#include <algorithm>
#include <iterator>

#include "race.h"

constexpr const unsigned Race::pointsForPlace[40];

Race::Race(std::string t, ContestantList* ptrContList) :
    type(t), ptrContestantList(ptrContList)
{
    // empty;
}

Race::Race(ContestantList* ptrContList) :
    ptrContestantList(ptrContList)
{
    // empty;
}

Race::~Race()
{
    // empty;
}

std::string Race::getType() const
{
    return type;
}

unsigned Race::getContestantPoints(Contestant* ptrCont) const
{
    for (unsigned i = 0; i < vectResult.size(); ++i)
    {
        if (ptrCont == vectResult[i])
        {
            return (i < 40) ? Race::pointsForPlace[i] : 0;
        }
    }
    return 0;
}

std::vector<Contestant*> Race::getVectResult() const
{
    return vectResult;
}

void Race::setType(std::string t)
{
    type = t;
}

void Race::setResult()
{
    vectResult.resize( ptrContestantList->getSetPtrContestants().size() );
    for (Contestant* contestant : ptrContestantList->getSetPtrContestants())
    {
        unsigned place;
        //std::cout << "Contestant " << contestant->getName() << " finished: ";
        std::cout << "Спаборнік " << contestant->getName() << " фінішыраваў: ";
        std::cin >> place;
        std::cin.ignore(80, '\n');
        vectResult.at(place - 1) = contestant;
    }
}
void Race::removeResult(Contestant* cont)
{
    auto iter =std::find(
                         vectResult.begin(),
                         vectResult.end(),
                         cont
                        );

    if ( iter != vectResult.end() )
    {
        vectResult.erase(iter);
    }
}

void Race::writeToFile(std::ostream& out)
{
    // write 'type' in file;
    unsigned len = type.size() + 1;
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reinterpret_cast<const char*>(type.c_str()), len);
    // write size of vector in file;
    len = vectResult.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    // write contestants in file
    for (Contestant* cont : vectResult)
    {
        cont->writeToFile(out);
    }
}

void Race::readFromFile(std::istream& in)
{
    // read "type" from file;
    unsigned len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    char* buf = new char[len];
    in.read(buf, len);
    type = buf;
    delete[] buf;

    vectResult.clear();
    // read size of vector from file;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));

    for (unsigned i = 0; i < len; ++i)
    {
        Contestant* temp = new Contestant();
        temp->readFromFile(in);
        // find this contestant in ContestantList;
        auto iter = ptrContestantList->getSetPtrContestants().find(temp);
        if (iter != ptrContestantList->getSetPtrContestants().end())
        {
            vectResult.push_back(*iter);
        }
        delete temp;
    }
}

std::ostream& operator<<(std::ostream& out, const Race& r)
{
    out << r.type << std::endl;

    //std::cout << "Result of race:\n";
    std::cout << "Вынікі гонкі:\n";
    for (unsigned i = 0; i < r.vectResult.size(); ++i)
    {
        if (i > 40)
        {
            std::cout << r.vectResult[i]->getName() << " - " << i + 1
                      << /*"\tPoints: "*/"\tБалы: " << 0 << std::endl;
        }
        else
        {
            std::cout << r.vectResult[i]->getName() << "\t-\t" << i + 1
                      << /*"\tPoints: "*/"\tБалы: " << Race::pointsForPlace[i] << std::endl;
        }
    }

    return out;
}
