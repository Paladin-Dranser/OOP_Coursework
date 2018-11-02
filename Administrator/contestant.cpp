#include "contestant.h"

Contestant::Contestant()
{
    // empty;
}

Contestant::Contestant(std::string n, std::string c) :
    name(n), country(c)
{
    // empty;
}

Contestant::~Contestant()
{
    // empty;
}

std::string Contestant::getName() const
{
    return name;
}

void Contestant::setName(std::string n)
{
    name = n;
}

void Contestant::setCountry(std::string c)
{
    country = c;
}

void Contestant::readFromFile(std::istream& in)
{
    unsigned len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    char* buf = new char[len];
    in.read(buf, len);
    name = buf;
    delete[] buf;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buf = new char[len];
    in.read(buf, len);
    country = buf;
    delete[] buf;
}

void Contestant::writeToFile(std::ostream& out) const
{
    unsigned len = name.size() + 1;
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reinterpret_cast<const char*>(name.c_str()), len);

    len = country.size() + 1;
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reinterpret_cast<const char*>(country.c_str()), len);
}

bool operator<(const Contestant& cont1, const Contestant& cont2)
{
    return cont1.name < cont2.name;
}

bool operator==(const Contestant& cont1, const Contestant& cont2)
{
    return (cont1.name == cont2.name) && (cont1.country == cont2.country);
}

std::ostream& operator<<(std::ostream& out, const Contestant& cont)
{
    out << cont.name << '\t' << cont.country << std::endl;
    return out;
}
