#ifndef COMPARERATINGROWBYALPHABETICAL_H
#define COMPARERATINGROWBYALPHABETICAL_H

#include "ratingrow.h"

class CompareRatingRowByAlphabetical
{
public:
    bool operator()(const RatingRow*, const RatingRow*) const;
};

#endif // COMPARERATINGROWBYALPHABETICAL_H
