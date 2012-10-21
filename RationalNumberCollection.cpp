#include "RationalNumberCollection.h"
#include "stdio.h"
#include "stdlib.h"

/*This struct represents a single RationalNumber in the RationalNumberCollection. In addition to the
  numerator and denominator, it contains an int for the count.*/
struct RationalNumberCollectionElement{
    RationalNumber rn;
    int count;
};

/*A RationalNumberCollection can contain different RationalNumbers
  and contains the count of each kind of RationalNumber*/
struct RationalNumberCollection {
    RationalNumberCollectionElement* collection;
    // totalUniqueCount can also be used as currentLength
    int totalUniqueCount;
    int totalCount;
    int capacity;
    RationalNumber sum;
    RationalNumber average;
    RationalNumber median;
};

bool rncInit(RationalNumberCollection* c, int capacity)
{
    c->average.numerator = 0;
    c->average.denominator = 0;

    c->median.numerator = 0;
    c->median.denominator = 0;

    c->sum.numerator = 0;
    c->sum.denominator = 0;

    c->totalCount = 0;
    c->totalUniqueCount = 0;
    c->capacity = capacity;

    for (int i = 0; i<capacity; i++)
    {
        c->collection[i].rn.numerator = 0;
        c->collection[i].rn.denominator = 0;
        c->collection[i].count = 0;
    }

    return true;
}

RationalNumberCollection *rncCreate(int capacity)
{
    RationalNumberCollection *c = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));
    c->collection = (RationalNumberCollectionElement*) malloc(capacity * sizeof(RationalNumberCollectionElement));
    rncInit(c, capacity);

    return c;
}

void rncDelete(RationalNumberCollection *c)
{
    free(c->collection);
    free(c);
}

// This function is called, when the capacity of the collection is not sufficient. After this function the capacity is 50% larger, and at least 10.
void rncIncreaseCapacity(RationalNumberCollection *c)
{
    int newCapicity;
    newCapicity = c->capacity + (c->capacity / 2);
    if (newCapicity < 10) newCapicity = 10;

    RationalNumberCollectionElement *newCollection = (RationalNumberCollectionElement *)malloc(newCapicity*sizeof(RationalNumberCollectionElement));

    // copying the old values into the newCollection
    for (int i=0; i<c->capacity; i++)
    {
        newCollection[i] = c->collection[i];
    }

    // free the old collection and set the collection pointer to the new one.
    free(c->collection);
    c->collection = newCollection;
    c->capacity = newCapicity;
}

// This function returns the position of the given RationalNumber in the collection, if the collection contains the given RationalNumber.
// It returns -1 if it doesn't contain it.
int rncGetPosition(RationalNumberCollection *c, RationalNumber n)
{    
    for (int i = 0; i<c->totalUniqueCount; i++)
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

// this function returns true, if the capacity is fully stretched
bool rncIsFull(RationalNumberCollection *c)
{
    if (c->totalUniqueCount >= c->capacity)
    {
        return true;
    }
    return false;
}

void rncUpdateTotalCount(RationalNumberCollection *c)
{
    int result = 0;

    for (int i=0 ; i < c->totalUniqueCount ; i++)
    {
        result += c->collection[i].count;
    }

    c->totalCount = result;
}

// This function calculates the sum of the collection by adding all of the RationalNumbers
void rncUpdateSum(RationalNumberCollection *c)
{
    // resultSum is 1/1 at first (so that it is not invalid)
    // this is subtracted before resultSum is returned
    RationalNumber resultSum;
    resultSum.numerator = 1;
    resultSum.denominator = 1;

    for (int i=0; i < c->totalUniqueCount; i++)
    {
        for (int j=0; j<c->collection[i].count; j++)
        {
            resultSum = rnAdd(resultSum, c->collection[i].rn);
        }
    }

    // Subtracting 1/1 from resultSum
    RationalNumber resultSumDiff;
    resultSumDiff.numerator = 1;
    resultSumDiff.denominator = 1;

    resultSum = rnSubtract(resultSum, resultSumDiff);

    c->sum = resultSum;

    // In case of the collection is empty, the sum is 0/0
    if (c->totalUniqueCount == 0)
    {
        c->sum.numerator = 0;
        c->sum.denominator = 0;
    }
}

// This function calculates the average value of the collection by dividing the sum by the number of RationalNumbers
void rncUpdateAverage(RationalNumberCollection *c)
{
    if (c->totalCount < 1)
    {
        c->average.numerator = 0;
        c->average.denominator = 0;
    }
    else
    {
        RationalNumber totalCountRN;
        totalCountRN.numerator = c->totalCount;
        totalCountRN.denominator = 1;

        RationalNumber result = rnDivide(c->sum, totalCountRN);
        c->average = result;
    }
}

// This function gets the current median value by calculating which rational number has the smallest difference to the average
void rncUpdateMedian(RationalNumberCollection *c)
{
    if (c->totalCount < 1)
    {
        c->median.numerator = 0;
        c->median.denominator = 0;
    }
    else
    {
        RationalNumber averageStart = c->average;

        RationalNumber resultRNDiff;
        int resultRNPosition;

        RationalNumber averageLoop;
        RationalNumber currentPositionRNDiff;

        for (int i=0; i<c->totalUniqueCount; i++)
        {
            averageLoop = c->average;

            RationalNumber currentPositionRN = c->collection[i].rn;

            if (rnIsNegative(averageLoop) && rnIsNegative(currentPositionRN))
            {
                averageLoop.numerator = abs(averageLoop.numerator);
                averageLoop.denominator = abs(averageLoop.denominator);
                currentPositionRN.numerator = abs(currentPositionRN.numerator);
                currentPositionRN.denominator = abs(currentPositionRN.denominator);
                if (rnLessThan(averageLoop,currentPositionRN))
                {
                    currentPositionRNDiff = rnSubtract(currentPositionRN, averageLoop);
                }
                else
                {
                    currentPositionRNDiff = rnSubtract(averageLoop, currentPositionRN);
                }

            }
            else if (rnIsNegative(averageLoop))
            {
                averageLoop.numerator = abs(averageLoop.numerator);
                averageLoop.denominator = abs(averageLoop.denominator);

                currentPositionRNDiff = rnAdd(averageLoop, currentPositionRN);
            }
            else if (rnIsNegative(currentPositionRN))
            {
                currentPositionRN.numerator = abs(currentPositionRN.numerator);
                currentPositionRN.denominator = abs(currentPositionRN.denominator);

                currentPositionRNDiff = rnAdd(averageStart, currentPositionRN);
            }
            else
            {
                if (rnLessThan(averageLoop,currentPositionRN))
                {
                    currentPositionRNDiff = rnSubtract(currentPositionRN, averageLoop);
                }
                else
                {
                    currentPositionRNDiff = rnSubtract(averageLoop, currentPositionRN);
                }
            }

            if (i==0)
            {
                resultRNDiff = currentPositionRNDiff;
                resultRNPosition = i;
            }

            // saving the position of the value most near to the average
            if (rnLessThan(currentPositionRNDiff, resultRNDiff))
            {
                resultRNDiff = currentPositionRNDiff;
                resultRNPosition = i;
            }
        }
        c->median = c->collection[resultRNPosition].rn;
    }
}

// This method is called to update all informational elements of the collection after an element has been added or removed
void rncUpdateCollection(RationalNumberCollection *c)
{
    rncUpdateTotalCount(c);
    rncUpdateSum(c);
    rncUpdateAverage(c);
    rncUpdateMedian(c);
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
    // if the capacity is insufficient rncIncreaseCapacity is called and rncAdd is called again.
    else if (rncIsFull(c))
    {
        rncIncreaseCapacity(c);
        return rncAdd(c, n);
    }

    // When a new RationalNumber is added to an empty collection, the order is ignored.
    else if (c->totalUniqueCount == 0)
    {
        c->collection[c->totalUniqueCount].rn.numerator = n.numerator;
        c->collection[c->totalUniqueCount].rn.denominator = n.denominator;
        c->collection[c->totalUniqueCount].count = 1;

        // increasing the current length of the collection (via totalUniqueCount)
        c->totalUniqueCount++;
        rncUpdateCollection(c);
        return true;
    }
    // When a new RationalNumber is added to a filled collection, it checks for the right position (the collection is ordered in ascending values)
    else
    {
        // this int represents the position in which the new value is saved for providing the ascending order.
        // if the rational number is larger than all of the other entries, it gets to the last position.
        int insertPosition = c->totalUniqueCount;

        for (int i=0; i<c->totalUniqueCount; i++)
        {
            if (rnLessThan(n, c->collection[i].rn))
            {
                insertPosition = i;
                break;
            }
        }

        // moving all following RationalNumbers to keep the ascending order
        for (int i=c->totalUniqueCount; i>insertPosition; i--)
        {
            c->collection[i].rn = c->collection[i-1].rn;
            c->collection[i].count = c->collection[i-1].count;
        }

        // addind the new RationalNumber in the correct position
        c->collection[insertPosition].rn.numerator = n.numerator;
        c->collection[insertPosition].rn.denominator = n.denominator;
        c->collection[insertPosition].count = 1;

        // increasing the currentLength of the collection
        c->totalUniqueCount++;
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
    // have to be moved to avoid an empty index
    else
    {
        for (int i=position; i<c->totalUniqueCount; i++)
        {
            RationalNumber tempRN = c->collection[i+1].rn;
            int tempCount = c->collection[i+1].count;

            c->collection[i].rn = tempRN;
            c->collection[i].count = tempCount;
        }

        c->totalUniqueCount--;
        rncUpdateCollection(c);
        return true;
    }
}

int rncTotalCount(RationalNumberCollection *c)
{
    return c->totalCount;
}

int rncTotalUniqueCount(RationalNumberCollection *c)
{
    return c->totalUniqueCount;
}

RationalNumber rncSum(RationalNumberCollection *c)
{
    return c->sum;
}

RationalNumber rncAverage(RationalNumberCollection *c)
{
    return c->average;
}

RationalNumber rncMedian(RationalNumberCollection *c)
{
    return c->median;
}

RationalNumber rncGetRNAtPosition(RationalNumberCollection *c,int i)
{
    return c->collection[i].rn;
}
