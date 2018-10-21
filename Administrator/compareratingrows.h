#ifndef COMPARERATINGROWS_H
#define COMPARERATINGROWS_H

#include "ratingrow.h"

class CompareRatingRows
{
public:
    bool operator()(const RatingRow&, const RatingRow&) const;
};

#endif // COMPARERATINGROWS_H
