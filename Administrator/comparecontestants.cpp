#include "comparecontestants.h"

bool CompareContestants::operator()(const Contestant* ptrCont1, const Contestant* ptrCont2) const
{
    return *ptrCont1 < *ptrCont2;
}
