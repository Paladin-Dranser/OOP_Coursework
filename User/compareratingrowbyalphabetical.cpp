#include "compareratingrowbyalphabetical.h"

bool CompareRatingRowByAlphabetical::operator()
        (const RatingRow* row1, const RatingRow* row2) const
{
    return row1->getName() < row2->getName();
}
