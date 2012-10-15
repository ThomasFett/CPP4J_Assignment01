#include "RationalNumberCollection.h"
#include "stdio.h"

void rncInit(RationalNumberCollection* c)
{
    c->average = 0;
    c->median = 0;
    c->sum = 0;
    c->totalCount = 0;
    c->totalUniqueCount = 0;

    for (int i = 0; i<1000; i++)
    {
        c->collection[i].rn.numerator = 0;
        c->collection[i].rn.denominator = 0;
        c->collection[i].count = 0;
    }
}

// This method returns true, if the collection contains the given RationalNumber
bool rncContains(RationalNumberCollection *c, RationalNumber n)
{
    return false;
}


bool rncAdd(RationalNumberCollection *c, RationalNumber n)
{
    return false;
}
