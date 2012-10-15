#ifndef HEADER_H
#define HEADER_H

struct RationalNumber
{
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);
int normalize(int, int);

RationalNumber normalizeFunction(RationalNumber);

bool rnEqual(RationalNumber, RationalNumber);
bool rnLessThan(RationalNumber, RationalNumber);
RationalNumber rnAdd(RationalNumber, RationalNumber);
RationalNumber rnSubtract(RationalNumber, RationalNumber);
RationalNumber rnMultiply(RationalNumber, RationalNumber);
RationalNumber rnDivide(RationalNumber, RationalNumber);

#endif // HEADER_H
