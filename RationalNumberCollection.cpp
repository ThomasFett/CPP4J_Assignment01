#include "RationalNumberCollection.h"
#include "stdio.h"

bool rncInit(RationalNumberCollection* c)
{
    c->average.numerator = 0;
    c->average.denominator = 0;

    c->median.numerator = 0;
    c->median.denominator = 0;

    c->sum.numerator = 0;
    c->sum.denominator = 0;

    c->currentLength = 0;
    c->totalCount = 0;
    c->totalUniqueCount = 0;

    for (int i = 0; i<1000; i++)
    {
        c->collection[i].rn.numerator = 0;
        c->collection[i].rn.denominator = 0;
        c->collection[i].count = 0;
    }

    return true;
}

// This method returns the position of the rational number in the collection, if the collection contains the given RationalNumber.
// It returns -1 if it doesn't contain it.
int rncContains(RationalNumberCollection *c, RationalNumber n)
{
    for (int i = 0; i<c->currentLength; i++)
    {
        if (c->collection[i].rn.numerator == n.numerator)
        {
            if (c->collection[i].rn.denominator == n.denominator)
            {
                return i;
            }
        }
    }

    return -1;
}

bool rncIsFull(RationalNumberCollection *c)
{
    if (c->currentLength >= 1000)
    {
        return true;
    }
    return false;
}

bool rncAdd(RationalNumberCollection *c, RationalNumber n)
{
    int position = rncContains(c, n);

    if (position != -1)
    {
        c->collection[position].count++;
        return true;
    }
    else if (rncIsFull(c))
    {
        printf("The RationalNumberCollection is already full! It can only contain up to 1000 different RationalNumbers!");
        return false;
    }
    else
    {
        c->collection[c->currentLength].rn.numerator = n.numerator;
        c->collection[c->currentLength].rn.denominator = n.denominator;
        c->collection[c->currentLength].count = 1;

        // increasing the currentLength of the collection
        c->currentLength++;
    }
}
