#ifndef COMPARERATINGROWBYPOINTS_H
#define COMPARERATINGROWBYPOINTS_H

#include "ratingrow.h"

class CompareRatingRowByPoints
{
public:
    bool operator()(const RatingRow*, const RatingRow*) const;
};

#endif // COMPARERATINGROWBYPOINTS_H
