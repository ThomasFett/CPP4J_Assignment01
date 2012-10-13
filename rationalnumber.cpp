#include "rationalnumber.h"
#include <stdio.h>;
#include <stdlib.h>;

// The modern Euclidian Algorithm
int rnEuclid(int a, int b)
{
    if (b==0) return a;
    return rnEuclid(b, a%b);
}

// Normalizes the given RationalNumber using the Euclidian Algorithm
RationalNumber rnNormalize(RationalNumber n)
{
    int gcd = rnEuclid(n.numerator, n.denominator);
    n.numerator = n.numerator/gcd;
    n.denominator = n.denominator/gcd;

    return n;
}

// Returns true if the given RationalNumber is negative (when the denominator is negative and the numerator positive and other way round).
bool rnIsNegative(RationalNumber n)
{
    if ((n.numerator > 0 && n.denominator > 0) || (n.numerator < 0 && n.denominator < 0)) return false;

    return true;
}

bool rnIsValid(RationalNumber n)
{
    if (n.denominator == 0) return false;

    return true;
}

bool rnEqual(RationalNumber n1, RationalNumber n2)
{
    n1 = rnNormalize(n1);
    n2 = rnNormalize(n2);

    if (n1.numerator == n2.numerator && n1.denominator == n2.denominator) return true;

    return false;
}

// all cases for positive and negative RationalNumbers are calculated seperately
bool rnLessThan(RationalNumber n1, RationalNumber n2)
{
    if (rnIsNegative(n1) && !rnIsNegative(n2)) return true;

    if (!rnIsNegative(n1) && rnIsNegative(n2)) return false;

    if (!rnIsNegative(n1) && !rnIsNegative(n2))
    {
        n1.numerator = abs(n1.numerator) * abs(n2.denominator);
        n2.numerator = abs(n2.numerator) * abs(n1.denominator);

        if (n1.numerator < n2.numerator) return true;
        return false;
    }

    if (rnIsNegative(n1) && rnIsNegative(n2))
    {
        n1.numerator = abs(n1.numerator) * abs(n2.denominator);
        n2.numerator = abs(n2.numerator) * abs(n1.denominator);

        if (n1.numerator > n2.numerator) return true;
        return false;
    }

    return false;
}

RationalNumber rnAdd(RationalNumber n1, RationalNumber n2)
{
    RationalNumber result;

    result.numerator = (n1.numerator * n2.denominator) + (n2.numerator *n1.denominator);
    result.denominator = (n1.denominator * n2.denominator);

    result = rnNormalize(result);

    return result;
}

RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2)
{
    RationalNumber result;

    result.numerator = (n1.numerator * n2.denominator) - (n2.numerator *n1.denominator);
    result.denominator = (n1.denominator * n2.denominator);

    result = rnNormalize(result);

    return result;
}

RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2)
{
    RationalNumber result;

    result.numerator = n1.numerator * n2.numerator;
    result.denominator = n1.denominator * n2.denominator;

    result = rnNormalize(result);

    return result;
}

RationalNumber rnDivide(RationalNumber n1, RationalNumber n2)
{
    RationalNumber result;

    // checking if a division is possible
    if (!rnIsValid(n1) || !rnIsValid(n2) )
    {
        printf("One of the RationalNumbers is NOT valid! The result of this function is not correct!");
        return result;
    }

    result.numerator = n1.numerator * n2.denominator;
    result.denominator = n1.denominator * n2.numerator;

    result = rnNormalize(result);

    return result;
}
