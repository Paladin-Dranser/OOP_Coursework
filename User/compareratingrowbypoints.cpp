#include "compareratingrowbypoints.h"

bool CompareRatingRowByPoints::operator()
    (const RatingRow* row1, const RatingRow* row2) const
{
    return row1->getPoints() < row2->getPoints();
}
