#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

// the structr that represents a rational number (German: "numerator" is "Zaehler" & "denominator" is "Nenner").
struct RationalNumber {
    int numerator;
    int denominator;
};

/* Declarations of all the functions that are used in 'testRN.cpp'. The function that normalizes a RationalNumber is not public yet and only
used in the implementation file('rationalnumber.cpp'). */

bool rnIsValid(RationalNumber n);
bool rnEqual(RationalNumber n1, RationalNumber n2);
bool rnLessThan(RationalNumber n1, RationalNumber n2);
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);
RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2);
RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2);
RationalNumber rnDivide(RationalNumber n1, RationalNumber n2);

#endif // RATIONALNUMBER_H
