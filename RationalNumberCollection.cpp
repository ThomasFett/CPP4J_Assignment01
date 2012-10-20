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

bool rncRemove(RationalNumberCollection *c, RationalNumber n)
{
    int position;
    position = rncGetPosition(c, n);

    // case one: the RationalNumber is not in the collection
    if (position == -1)
    {
        return true;
    }

    // case two: the RationalNumber is in the collection more than one time
    else if (c->collection[position].count > 1)
    {
        c->collection[position].count--;
        rncUpdateCollection(c);
        return false;
    }

    // case three: the RationalNumber is in the collection one time. The Following entries in the collection
    // have to moved to avoid an empty index
    else
    {
        for (int i=position; i<c->currentLength; i++)
        {
            RationalNumber tempRN = c->collection[i+1].rn;
            int tempCount = c->collection[i+1].count;

            c->collection[i].rn = tempRN;
            c->collection[i].count = tempCount;
        }

        c->currentLength--;
        rncUpdateCollection(c);
        return true;
    }
}

int rncTotalCount(RationalNumberCollection *c)
{
    return c->totalCount;
}
