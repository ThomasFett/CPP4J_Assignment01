#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include <RationalNumber.h>;

struct RationalNumberCollection {
    int collection[1500];
};

void rncInit(RationalNumberCollection* c);

void rncAdd(RationalNumberCollection* c, RationalNumber n);

int rncCount(RationalNumberCollection* c, RationalNumber n);

bool rncRemove(RationalNumberCollection* c, RationalNumber n);

int rncTotalUniqueCount(RationalNumberCollection* c);

int rncTotalCount(RationalNumberCollection* c);

RationalNumber rncSum(RationalNumberCollection* c);

RationalNumber rncAverage(RationalNumberCollection* c);

RationalNumber rncMedian(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
