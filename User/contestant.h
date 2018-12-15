#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <fstream>
#include <iostream>

#include <string>

class Contestant
{
public:
    Contestant();
    Contestant(std::string n, std::string c);
    ~Contestant();

    std::string getName() const;
    void readFromFile(std::istream& in);

    friend bool operator<(const Contestant&, const Contestant&);
    friend bool operator==(const Contestant&, const Contestant&);
    friend std::ostream& operator<<(std::ostream&, const Contestant&);
private:
    std::string name;
    std::string country;
};

#endif // CONTESTANT_H
