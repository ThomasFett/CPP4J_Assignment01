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

    printf("RNC-Test Checkpoint 1!\n");

    rncAdd(&c, testRn1_2);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 1);
    assert(rncTotalCount(&c) == 1);
    assert(rncTotalUniqueCount(&c) == 1);
    assert(rncCount(&c, testRn1_2) == 1);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 0);

    RationalNumber collectionSum = rncSum(&c);
    assert(collectionSum.numerator == 1);
    assert(collectionSum.denominator == 2);

    RationalNumber collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == 1);
    assert(collectionAverage.denominator == 2);


    printf("RNC-Test Checkpoint 2!\n");

    rncAdd(&c, testRn1_2);

    assert(c.collection[0].rn.numerator == 1);
    assert(c.collection[0].rn.denominator == 2);
    assert(c.collection[0].count == 2);
    assert(rncTotalCount(&c) == 2);
    assert(rncTotalUniqueCount(&c) == 1);
    assert(rncCount(&c, testRn1_2) == 2);
    assert(rncCount(&c, testRn5_4) == 0);
    assert(rncCount(&c, testRnMin98827_82) == 0);

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == 1);
    assert(collectionSum.denominator == 1);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == 1);
    assert(collectionAverage.denominator == 2);

    printf("RNC-Test Checkpoint 3!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == 9);
    assert(collectionSum.denominator == 4);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == 3);
    assert(collectionAverage.denominator == 4);

    printf("RNC-Test Checkpoint 4!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);

    printf("RNC-Test Checkpoint 5!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == -197203);
    assert(collectionSum.denominator == 164);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == -197203);
    assert(collectionAverage.denominator == 820);

    printf("RNC-Test Checkpoint 6!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == -49352);
    assert(collectionSum.denominator == 41);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == -12338);
    assert(collectionAverage.denominator == 41);

    printf("RNC-Test Checkpoint 7!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);

    printf("RNC-Test Checkpoint 8!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == 0);
    assert(collectionSum.denominator == 0);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == 0);
    assert(collectionAverage.denominator == 0);

    printf("RNC-Test Checkpoint 9!\n");

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

    collectionSum = rncSum(&c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(&c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);

    printf("RNC-Test has completed succesfully!\n");
}
