/*
   Simple Unit Test for type RationalNumberCollection
*/


#include <stdio.h>
#include <assert.h>

#include "RationalNumberCollection.h";

int main()
{
    printf("simpleTest has started!\n");

    RationalNumber test1 = {6,-4};
    RationalNumber test2 = {-7,-4};

    assert( rnLessThan( test1, test2) );

    RationalNumber testResult = rnMultiply(test1, test2);

    printf("simpleTest has completed!\n");

    printf("RNC-Test has started!\n");

    RationalNumberCollection *c = rncCreate(1000);

    RationalNumber index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == 0);
    assert(index0.denominator == 0);
    assert(rncTotalCount(c) == 0);

    RationalNumber testRn1_2 = {1,2};
    RationalNumber testRn5_4 = {5,4};
    RationalNumber testRnMin98827_82 = {-98827,82};
    RationalNumber testRn1_1 = {1,1};
    RationalNumber testRNMIN2_5 ={2,-5};

    printf("RNC-Test Checkpoint 1!\n");

    rncAdd(c, testRn1_2);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == 1);
    assert(index0.denominator == 2);
    assert(rncTotalCount(c) == 1);
    assert(rncTotalUniqueCount(c) == 1);
    assert(rncCount(c, testRn1_2) == 1);
    assert(rncCount(c, testRn5_4) == 0);
    assert(rncCount(c, testRnMin98827_82) == 0);

    RationalNumber collectionSum = rncSum(c);
    assert(collectionSum.numerator == 1);
    assert(collectionSum.denominator == 2);

    RationalNumber collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == 1);
    assert(collectionAverage.denominator == 2);

    RationalNumber collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 2!\n");

    rncAdd(c, testRn1_2);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == 1);
    assert(index0.denominator == 2);
    assert(rncTotalCount(c) == 2);
    assert(rncTotalUniqueCount(c) == 1);
    assert(rncCount(c, testRn1_2) == 2);
    assert(rncCount(c, testRn5_4) == 0);
    assert(rncCount(c, testRnMin98827_82) == 0);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == 1);
    assert(collectionSum.denominator == 1);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == 1);
    assert(collectionAverage.denominator == 2);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 3!\n");

    rncAdd(c, testRn5_4);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == 1);
    assert(index0.denominator == 2);

    RationalNumber index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 5);
    assert(index1.denominator == 4);

    RationalNumber index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 0);
    assert(index2.denominator == 0);

    assert(rncTotalCount(c) == 3);
    assert(rncTotalUniqueCount(c) == 2);
    assert(rncCount(c, testRn1_2) == 2);
    assert(rncCount(c, testRn5_4) == 1);
    assert(rncCount(c, testRnMin98827_82) == 0);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == 9);
    assert(collectionSum.denominator == 4);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == 3);
    assert(collectionAverage.denominator == 4);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 4!\n");

    rncAdd(c, testRn1_2);
    rncAdd(c, testRn5_4);
    rncAdd(c, testRnMin98827_82);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 5);
    assert(index2.denominator == 4);

    RationalNumber index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 6);
    assert(rncTotalUniqueCount(c) == 3);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 2);
    assert(rncCount(c, testRnMin98827_82) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);


    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 5!\n");

    rncRemove(c, testRn5_4);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 5);
    assert(index2.denominator == 4);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 5);
    assert(rncTotalUniqueCount(c) == 3);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 1);
    assert(rncCount(c, testRnMin98827_82) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -197203);
    assert(collectionSum.denominator == 164);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -197203);
    assert(collectionAverage.denominator == 820);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 6!\n");

    rncRemove(c, testRn5_4);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 0);
    assert(index2.denominator == 0);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 4);
    assert(rncTotalUniqueCount(c) == 2);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 0);
    assert(rncCount(c, testRnMin98827_82) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -49352);
    assert(collectionSum.denominator == 41);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -12338);
    assert(collectionAverage.denominator == 41);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 7!\n");

    rncAdd(c, testRn5_4);
    rncAdd(c, testRn5_4);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 5);
    assert(index2.denominator == 4);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 6);
    assert(rncTotalUniqueCount(c) == 3);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 2);
    assert(rncCount(c, testRnMin98827_82) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 8!\n");

    rncRemove(c, testRn1_2);
    rncRemove(c, testRn1_2);
    rncRemove(c, testRn1_2);
    rncRemove(c, testRn5_4);
    rncRemove(c, testRn5_4);
    rncRemove(c, testRnMin98827_82);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == 0);
    assert(index0.denominator == 0);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 0);
    assert(index1.denominator == 0);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 0);
    assert(index2.denominator == 0);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 0);
    assert(rncTotalUniqueCount(c) == 0);
    assert(rncCount(c, testRn1_2) == 0);
    assert(rncCount(c, testRn5_4) == 0);
    assert(rncCount(c, testRnMin98827_82) == 0);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == 0);
    assert(collectionSum.denominator == 0);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == 0);
    assert(collectionAverage.denominator == 0);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 0);
    assert(collectionMedian.denominator == 0);


    printf("RNC-Test Checkpoint 9!\n");

    rncAdd(c, testRn1_2);
    rncAdd(c, testRn1_2);
    rncAdd(c, testRn1_2);
    rncAdd(c, testRn5_4);
    rncAdd(c, testRn5_4);
    rncAdd(c, testRnMin98827_82);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 5);
    assert(index2.denominator == 4);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 0);
    assert(index3.denominator == 0);

    assert(rncTotalCount(c) == 6);
    assert(rncTotalUniqueCount(c) == 3);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 2);
    assert(rncCount(c, testRnMin98827_82) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -98499);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -32833);
    assert(collectionAverage.denominator == 164);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    printf("RNC-Test Checkpoint 10!\n");

    rncAdd(c, testRn1_1);

    index0 = rncGetRNAtPosition(c,0);
    assert(index0.numerator == -98827);
    assert(index0.denominator == 82);

    index1 = rncGetRNAtPosition(c,1);
    assert(index1.numerator == 1);
    assert(index1.denominator == 2);

    index2 = rncGetRNAtPosition(c,2);
    assert(index2.numerator == 1);
    assert(index2.denominator == 1);

    index3 = rncGetRNAtPosition(c,3);
    assert(index3.numerator == 5);
    assert(index3.denominator == 4);

    RationalNumber index4 = rncGetRNAtPosition(c,4);
    assert(index4.numerator == 0);
    assert(index4.denominator == 0);

    assert(rncTotalCount(c) == 7);
    assert(rncTotalUniqueCount(c) == 4);
    assert(rncCount(c, testRn1_2) == 3);
    assert(rncCount(c, testRn5_4) == 2);
    assert(rncCount(c, testRnMin98827_82) == 1);
    assert(rncCount(c, testRn1_1) == 1);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == -98417);
    assert(collectionSum.denominator == 82);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == -98417);
    assert(collectionAverage.denominator == 574);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 2);

    rncAdd(c, testRNMIN2_5);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 2);
    assert(collectionMedian.denominator == -5);

    printf("RNC-Test Checkpoint 11!\n");

    rncRemove(c, testRnMin98827_82);
    rncRemove(c, testRNMIN2_5);

    collectionSum = rncSum(c);
    assert(collectionSum.numerator == 5);
    assert(collectionSum.denominator == 1);

    collectionAverage = rncAverage(c);
    assert(collectionAverage.numerator == 5);
    assert(collectionAverage.denominator == 6);

    collectionMedian = rncMedian(c);
    assert(collectionMedian.numerator == 1);
    assert(collectionMedian.denominator == 1);

    rncDelete(c);

    printf("RNC-Test has completed succesfully!\n");
}
