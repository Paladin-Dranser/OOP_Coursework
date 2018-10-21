#include "compareratingrows.h"

bool operator()(const RatingRow& row1, const RatingRow& row2) const
{
    return row1 < row2;
}
