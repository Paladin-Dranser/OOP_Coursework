#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "contestantlist.h"

class Race
{
public:
    Race(std::string t, ContestantList* ptrContList);
    Race(ContestantList* ptrContList);
    ~Race();
    std::string getType() const;
    unsigned getContestantPoints(Contestant*) const;
    std::vector<Contestant*> getVectResult() const;
    void setType(std::string);
    void setResult();
    void removeResult(Contestant*);

    void writeToFile(std::ostream& out);
    void readFromFile(std::istream& in);

    friend std::ostream& operator<<(std::ostream&, const Race&);
private:
    std::string type;
    ContestantList* ptrContestantList;
    std::vector<Contestant*> vectResult;
    static constexpr unsigned pointsForPlace[40] =
    {
        60, 54, 48, 43, 40, 38, 36, 34, 32, 31,
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
};

#endif // RACE_H
