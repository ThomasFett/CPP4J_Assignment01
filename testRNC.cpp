/*
   Simple Unit Test for type RationalNumberCollection
*/


#include <stdio.h>
#include <assert.h>

#include "RationalNumberCollection.h";

int main()
{
    /*printf("simpleTest has started!\n");

    RationalNumber test1 = {6,-4};
    RationalNumber test2 = {-7,-4};

    assert( rnLessThan( test1, test2) );

    printf("Test1 is: %i / %i \n", test1.numerator, test1.denominator);
    printf("Test2 is: %i / %i \n", test2.numerator, test2.denominator);

    RationalNumber testResult = rnMultiply(test1, test2);

    printf("The result rn is: %i / %i\n", testResult.numerator, testResult.denominator);

    printf("simpleTest has completed!\n");*/

    printf("RNC-Test has started!\n");

    RationalNumberCollection c;

    assert(!(rncTotalCount(&c) == 0));

    rncInit(&c);

    assert(rncTotalCount(&c) == 0);


    printf("RNC-Test has completed!\n");
}
