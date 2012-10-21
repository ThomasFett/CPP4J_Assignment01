#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

// the struct that represents a rational number (German: "numerator" is "Zaehler" & "denominator" is "Nenner").
struct RationalNumber {
    int numerator;
    int denominator;
};

/* Declarations of all the functions that are used in 'testRN.cpp'. The function that normalizes a RationalNumber is not public yet and only
used in the implementation file('rationalnumber.cpp'). */

// Returns true if the denominator is not 0.
bool rnIsValid(RationalNumber n);

// Returns true if numerator & denominator of n1 and n2 are equal
bool rnEqual(RationalNumber n1, RationalNumber n2);

// Return true if n1 is less than n2
bool rnLessThan(RationalNumber n1, RationalNumber n2);

// adds n1 to n2
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);

// subtracts n2 from n1
RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2);

// adds n1 with n2
RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2);

// divides n1 by n2
RationalNumber rnDivide(RationalNumber n1, RationalNumber n2);

// returns if the given RationalNumber is negative
bool rnIsNegative(RationalNumber n);

#endif // RATIONALNUMBER_H
