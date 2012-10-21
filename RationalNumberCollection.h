#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include <RationalNumber.h>;

/*A RationalNumberCollection can contain different RationalNumbers
  and contains the count of each kind of RationalNumber*/
struct RationalNumberCollection;

// This function creates a RationalNumberCollectin with the given start capacity and returns its pointer
RationalNumberCollection *rncCreate(int capacity);

// This function deletes the given RationalNumberCollection
void rncDelete(RationalNumberCollection *c);

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

// This method is only for testing purpose! Don't use it in your programs, because it is already deprecated ;-)
RationalNumber rncGetRNAtPosition(RationalNumberCollection *c,int i);

#endif // RATIONALNUMBERCOLLECTION_H
