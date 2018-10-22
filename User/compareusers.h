#ifndef COMPAREUSERS_H
#define COMPAREUSERS_H

#include "user.h"

class CompareUsers
{
public:
    bool operator()(const User*, const User*) const;
};

#endif // COMPAREUSERS_H
