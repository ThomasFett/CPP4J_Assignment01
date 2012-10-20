#include <iostream>
#include <RationalnumberCollection.h>
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct RationalnumberCollectionElement{
    RationalNumber rn;
    int count;
};

struct RationalnumberCollection{
    RationalnumberCollectionElement* collection;
    int capacity;
};

RationalnumberCollection* rncCreate(int capacity){
    //reserviert speicher für die RNC
    RationalnumberCollection* obj = (RationalnumberCollection*) malloc(1*sizeof(RationalnumberCollection));
    obj->capacity = capacity;
    obj->collection = (RationalnumberCollectionElement*) malloc(obj->capacity*sizeof( RationalnumberCollectionElement));
    rncInit(obj);
    return obj;
}

int rncInit( RationalnumberCollection* c ){

    cout << "init(): " << endl;
    for ( int i = 0; i < (c->capacity); i+=1){
        c->collection[i].rn.denominator = 0;
        c->collection[i].rn.numerator = 0;
        c->collection[i].count = 0;
    }
    return 0;
}


void rncDelete(RationalnumberCollection* c){
    free(c->collection);
    free(c);
    cout << "Free Willy!" << endl;
}

void showAllNumbers(RationalnumberCollection* c){
    cout << "show all Numbers: " << endl;
    for ( int i = 0; i < (c->capacity); i++ ){
        cout << c->collection[i].rn.numerator << " / " << c->collection[i].rn.denominator
             << "  -->  "<<  c->collection[i].count << endl;
     }
}

//return index of Rationalnumber when Rationalnumber is in collection - else return 0;
int rncContains(RationalNumber a, RationalnumberCollection* c ){
    for ( int i = 0; i < (c->capacity); i++ ){
        if(c->collection[i].rn.denominator == a.denominator && c->collection[i].rn.numerator == a.numerator){
            return i;
        }
    }
    return -1;
}

//return true when lenght of Rationalnumber ist bigger 1000
bool rncIsFull(RationalnumberCollection *c){
    if((c->capacity) > 1000){
        return true;
    }
    return false;
}


//return true when given Rationalnumber is added to Collection
bool rncAdd(RationalNumber a, RationalnumberCollection * c){

    int n = rncContains(a,c);

    //if RN is still in collection increase the counter
    if(n >= 0){
        c->collection[n].count += 1;

        return true;
    }else{
        for ( int i = 0; i < (c->capacity); i++ ){
            //if RN is still not in collection - insert RN to array
            if(c->collection[i].rn.denominator == 0 && c->collection[i].rn.numerator == 0){
                c->collection[i].rn.numerator = a.numerator;
                c->collection[i].rn.denominator = a.denominator;
                c->collection[i].count += 1;
                return true;
            }
        }
    }
    return false;
}

//return true whenn given Rationalnumber is removed from Collection
bool rncRemove(RationalNumber a, RationalnumberCollection * c){
    int n = rncContains(a,c);

    //if Rationalnumber is in Collection
    if(n >= 0){
        if(c->collection[n].count > 1){
            c->collection[n].count -= 1;
        }else{
            c->collection[n].count = 0;
            c->collection[n].rn.numerator = 0;
            c->collection[n].rn.denominator = 0;
        }
        return true;
    }
    return false;
}

//return sum of all fractions
RationalNumber rncSum ( RationalnumberCollection* c ){
    RationalNumber rnSum;
    rnSum.numerator = 0;
    rnSum.denominator = 0;
    for ( int i = 0; i < rncTotalCount(c); i++ ){
        for ( int j = 0; j < c->collection[i].count; j++ ){
            rnSum = normalizeFunction( rnAdd(rnSum, c->collection[i].rn) );
        }
    }
    return rnSum;
}

//return the average of all fractions
RationalNumber rncAverage ( RationalnumberCollection* c ){
    RationalNumber amount;
    amount.numerator = rncTotalCount ( c );
    amount.denominator = 1;
    RationalNumber sum = rncSum(c);
    return normalizeFunction( rnDivide( sum, amount ) );
}

/*  returns the median of all fractions
    ideas from http://www.brinkmann-du.de/mathe/gost/bstat_01_06.htm#abs1
    the median is the value in the middle of all fractions
*/
RationalNumber rncMedian ( RationalnumberCollection* c ){
    RationalNumber average = rncAverage ( c );
    RationalNumber value;
    value.numerator = 1;
    value.denominator = 1;
    RationalNumber smallestValue;
    smallestValue.numerator = 1;
    smallestValue.denominator = 1;
    int index;

    cout << "average: " << average.numerator << " / " << average.denominator << endl;

    cout << "TotalCount" << rncTotalUniqueCount(c) << endl;

    for ( int i = 0; i < rncTotalCount(c); i++ ){

        //differenz exception between the average and i
        value = rnSubtract( average, ( c->collection[i].rn ) );

        //convert to absolute values
        value.numerator = abs(value.numerator);
        value.denominator = abs(value.denominator);

        if(i == 0){
            smallestValue = value;
            index = i;
        }
        //ermittelt die kleinste differenz, zwischen average und i
        if( rnLessThan( value, smallestValue ))  {
            smallestValue = value;
            index = i;
        }
    }
    //gibt RN mit dem kleinsten differenz zurück
    return c->collection[index].rn;
}

//return the counter of fraction a
int rncCount ( RationalNumber a, RationalnumberCollection* c ){
    int n = rncContains(a,c);
    if(n >= 0){
        return c->collection[n].count;
    }
    return 0;
}

//return the amount of all DIFFERENT fractions
int rncTotalCount ( RationalnumberCollection* c ){
   int counter = 0;
   for ( int i = 0; i < (c->capacity); i++ ){
       counter += c->collection[i].count;
   }
   return counter;
}

//return the amount of all fractions
int rncTotalUniqueCount ( RationalnumberCollection* c){
    int counter = 0;
       for ( int i = 0; i < (c->capacity); i++ ){
           if(c->collection[i].rn.denominator != 0 && c->collection[i].rn.numerator != 0){
               counter ++;
           }
       }
    return counter;
}
