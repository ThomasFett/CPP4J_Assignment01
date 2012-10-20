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
int rncGetPosition(RationalNumberCollection *c, RationalNumber n)
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

void rncUpdateTotalCount(RationalNumberCollection *c)
{
    int result = 0;

    for (int i=0 ; i < c->currentLength ; i++)
    {
        result += c->collection[i].count;
    }

    c->totalCount = result;
}

// This method is called to update all informational elements of the collection after an element has been added or removed
void rncUpdateCollection(RationalNumberCollection *c)
{
    rncUpdateTotalCount(c);
}

int rncCount(RationalNumberCollection *c, RationalNumber n)
{
    int position;

    position = rncGetPosition(c, n);

    if (position != -1) return c->collection[position].count;

    return 0;
}

bool rncAdd(RationalNumberCollection *c, RationalNumber n)
{
    int position = rncGetPosition(c, n);

    if (position != -1)
    {
        c->collection[position].count++;
        rncUpdateCollection(c);
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
        rncUpdateCollection(c);
        return true;
    }
}

int rncTotalCount(RationalNumberCollection *c)
{
    return c->totalCount;
}
