#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include <RationalNumber.h>;

/*This struct represents a single RationalNumber in the RationalNumberCollection. In addition to the
  numerator and denominator, it contains an int for the count.*/
struct RationalNumberCollectionElement{
    RationalNumber rn;
    int count;
};
/*A RationalNumberCollection can contain up to 1000 different RationalNumbers
  and contains the count of each kind of RationalNumber*/
struct RationalNumberCollection {
    RationalNumberCollectionElement collection[1000];
    // totalUniqueCount can also be used as currentLength
    int totalUniqueCount;
    int totalCount;
    RationalNumber sum;
    RationalNumber average;
    RationalNumber median;
};

// inits the created RationalNumberCollection by filling it with zeros. Returns true, when all RNC-values are set to 0.
// CAUTION! Don't call this method, wenn the RNC is already in use!
bool rncInit(RationalNumberCollection* c);

// adds a given RationalNumber to the given RationalNumberCollection
bool rncAdd(RationalNumberCollection* c, RationalNumber n);

// Returns the count of the given RationalNumber. If the RationalNumber is not in the RNC the return value is 0.
int rncCount(RationalNumberCollection* c, RationalNumber n);

// removes a given RationalNumber from the given RationalNumberCollection
// returns TRUE if all RationalNumbers of this kind are removed afterwards
// returns FALSE if there are still RationalNumbers of that kind are left after the removal
bool rncRemove(RationalNumberCollection* c, RationalNumber n);

// returns the count of DIFFERENT RationalNUmbers in the collection
int rncTotalUniqueCount(RationalNumberCollection* c);

// returns the count of ALL RationalNumbers in the collection
int rncTotalCount(RationalNumberCollection* c);

// sums up ALL RationalNumbers in the collection
RationalNumber rncSum(RationalNumberCollection* c);

// calculates the average Value of ALL RationalNumbers in the collection
RationalNumber rncAverage(RationalNumberCollection* c);

// calculates the median value of ALL RationalNumbers in the collection
RationalNumber rncMedian(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
