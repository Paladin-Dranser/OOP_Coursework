#include "compareusers.h"

bool CompareUsers::operator()(const User* ptrUser1, const User* ptrUser2) const
{
    return *ptrUser1 < *ptrUser2;
}
