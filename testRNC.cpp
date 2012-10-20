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

    // before init-function:

    // init-function:
    rncInit(&c);

    // after init-function:
    assert(c.collection[0].rn.numerator == 0);
    assert(c.collection[0].rn.denominator == 0);
    assert(c.collection[0].count == 0);
    assert(rncTotalCount(&c) == 0);

    RationalNumber testRn1_2 = {1,2};
    RationalNumber testRn5_4 = {5,4};
    RationalNumber testRnMin98827_82 = {-98827,82};

    rncAdd(&c, testRn1_2);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 1);
    assert(rncTotalCount(&c) == 1);
    assert(rncTotalUniqueCount(&c) == 1);
    assert(rncCount(&c, testRn1_2) == 1);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 0);

    rncAdd(&c, testRn1_2);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 2);
    assert(rncTotalCount(&c) == 2);
    assert(rncTotalUniqueCount(&c) == 1);
    assert(rncCount(&c, testRn1_2) == 2);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 0);

    rncAdd(&c, testRn5_4);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 2);
    assert(c.collection[1].rn.numerator == 5);
    assert(c.collection[1].rn.denominator == 4);
    assert(c.collection[1].count == 1);
    assert(c.collection[2].rn.numerator == 0);
    assert(c.collection[2].rn.denominator == 0);
    assert(c.collection[2].count == 0);
    assert(rncTotalCount(&c) == 3);
    assert(rncTotalUniqueCount(&c) == 2);
    assert(rncCount(&c, testRn1_2) == 2);
    assert(rncCount(&c, testRn5_4) == 1);
    assert(rncCount(&c, testRnMin98827_82) == 0);


    rncAdd(&c, testRn1_2);
    rncAdd(&c, testRn5_4);
    rncAdd(&c, testRnMin98827_82);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 3);
    assert(c.collection[1].rn.numerator == 5);
    assert(c.collection[1].rn.denominator == 4);
    assert(c.collection[1].count == 2);
    assert(c.collection[2].rn.numerator == -98827);
    assert(c.collection[2].rn.denominator == 82);
    assert(c.collection[2].count == 1);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 6);
    assert(rncTotalUniqueCount(&c) == 3);
    assert(rncCount(&c, testRn1_2) == 3);
    assert(rncCount(&c, testRn5_4) == 2);
    assert(rncCount(&c, testRnMin98827_82) == 1);

    assert(c.totalUniqueCount == 3);

    rncRemove(&c, testRn5_4);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 3);
    assert(c.collection[1].rn.numerator == 5);
    assert(c.collection[1].rn.denominator == 4);
    assert(c.collection[1].count == 1);
    assert(c.collection[2].rn.numerator == -98827);
    assert(c.collection[2].rn.denominator == 82);
    assert(c.collection[2].count == 1);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 5);
    assert(rncTotalUniqueCount(&c) == 3);
    assert(rncCount(&c, testRn1_2) == 3);
    assert(rncCount(&c, testRn5_4) == 1);
    assert(rncCount(&c, testRnMin98827_82) == 1);

    assert(c.totalUniqueCount == 3);

    rncRemove(&c, testRn5_4);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 3);
    assert(c.collection[1].rn.numerator == -98827);
    assert(c.collection[1].rn.denominator == 82);
    assert(c.collection[1].count == 1);
    assert(c.collection[2].rn.numerator == 0);
    assert(c.collection[2].rn.denominator == 0);
    assert(c.collection[2].count == 0);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 4);
    assert(rncTotalUniqueCount(&c) == 2);
    assert(rncCount(&c, testRn1_2) == 3);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 1);

    assert(c.totalUniqueCount == 2);

    rncAdd(&c, testRn5_4);
    rncAdd(&c, testRn5_4);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 3);
    assert(c.collection[1].rn.numerator == -98827);
    assert(c.collection[1].rn.denominator == 82);
    assert(c.collection[1].count == 1);
    assert(c.collection[2].rn.numerator == 5);
    assert(c.collection[2].rn.denominator == 4);
    assert(c.collection[2].count == 2);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 6);
    assert(rncTotalUniqueCount(&c) == 3);
    assert(rncCount(&c, testRn1_2) == 3);
    assert(rncCount(&c, testRn5_4) == 2);
    assert(rncCount(&c, testRnMin98827_82) == 1);

    assert(c.totalUniqueCount == 3);

    rncRemove(&c, testRn1_2);
    rncRemove(&c, testRn1_2);
    rncRemove(&c, testRn1_2);
    rncRemove(&c, testRn5_4);
    rncRemove(&c, testRn5_4);
    rncRemove(&c, testRnMin98827_82);

    assert(c.collection[0].rn.numerator == 0);
    assert(c.collection[0].rn.denominator == 0);
    assert(c.collection[0].count == 0);
    assert(c.collection[1].rn.numerator == 0);
    assert(c.collection[1].rn.denominator == 0);
    assert(c.collection[1].count == 0);
    assert(c.collection[2].rn.numerator == 0);
    assert(c.collection[2].rn.denominator == 0);
    assert(c.collection[2].count == 0);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 0);
    assert(rncTotalUniqueCount(&c) == 0);
    assert(rncCount(&c, testRn1_2) == 0);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 0);

    assert(c.totalUniqueCount == 0);

    rncAdd(&c, testRn1_2);
    rncAdd(&c, testRn1_2);
    rncAdd(&c, testRn1_2);
    rncAdd(&c, testRn5_4);
    rncAdd(&c, testRn5_4);
    rncAdd(&c, testRnMin98827_82);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 3);
    assert(c.collection[1].rn.numerator == 5);
    assert(c.collection[1].rn.denominator == 4);
    assert(c.collection[1].count == 2);
    assert(c.collection[2].rn.numerator == -98827);
    assert(c.collection[2].rn.denominator == 82);
    assert(c.collection[2].count == 1);
    assert(c.collection[3].rn.numerator == 0);
    assert(c.collection[3].rn.denominator == 0);
    assert(c.collection[3].count == 0);
    assert(rncTotalCount(&c) == 6);
    assert(rncTotalUniqueCount(&c) == 3);
    assert(rncCount(&c, testRn1_2) == 3);
    assert(rncCount(&c, testRn5_4) == 2);
    assert(rncCount(&c, testRnMin98827_82) == 1);

    assert(c.totalUniqueCount == 3);

    printf("RNC-Test has completed succesfully!\n");
}
