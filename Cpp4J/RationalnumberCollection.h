#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H
#include <Rationalnumber.h>

struct RationalnumberCollection;

//return true when collection is > 1000
bool rncIsFull(RationalnumberCollection* c);

RationalnumberCollection* rncCreate(int capacity);

void rncDelete(RationalnumberCollection* c);

//search if RN is in c - when return index of RN else return 0;
int rncContains(RationalNumber a, RationalnumberCollection* c );

//print all Numbers
void showAllNumbers();

//initalize the array
int rncInit( RationalnumberCollection* a);

//return true when given Rationalnumber is added to Collection
bool rncAdd( RationalNumber a, RationalnumberCollection* c);

//return true whenn givven Rationalnumber is removed from Collection
bool rncRemove( RationalNumber a, RationalnumberCollection* c);

//return the counter of fraction a
int rncCount ( RationalNumber a, RationalnumberCollection* c );

//return the amount of all different fractions
int rncTotalUniqueCount ( RationalnumberCollection* c);

//return the amount of all fractions
int rncTotalCount ( RationalnumberCollection* c);

void showAllNumbers(RationalnumberCollection* c);

//return sum of all fractions
RationalNumber rncSum ( RationalnumberCollection* c);

//return the average of all fractions
RationalNumber rncAverage ( RationalnumberCollection* c);

//returns the median of all fractions
RationalNumber rncMedian ( RationalnumberCollection* c);


#endif // RATIONALNUMBERCOLLECTION_H
