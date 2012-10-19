#include <iostream>
#include <RationalnumberCollection.h>
#include <assert.h>

using namespace std;

RationalnumberCollection* c = rncCreate(10);

RationalNumber  n1 = { 1, 2 },
                n2 = { 1, 8 },
                n3 = { 5, 4 },
                n4 = { 9, 4 },
                n5 = { 3, 2 },
                n6 = { 1, 4 },
                n7 = { 1, 1 };

/*
Noch offene Methoden:
jUnit testbar
rncAddSort
*/

int main(){

    cout << "MAIN Start --> " << endl;

    rncAdd(n1, c);
    rncAdd(n2, c);
    rncAdd(n1, c);
    rncAdd(n3, c);
    rncAdd(n1, c);

    rncRemove(n2, c);
    rncAdd(n5, c);
    //rncAdd(n6, c);
    rncAdd(n6, c);
    //rncRemove(n6, c);


    RationalNumber av =  rncAverage(c);
    cout << "Mittelwert: " << av.numerator << " / " << av.denominator << endl;

    //RationalNumber me =  rncMedian(c);
    //cout << "Median: " << me.numerator << " / " << me.denominator << endl;

    RationalNumber sum =  rncSum(c);
    cout << "Gesamtsumme: " << sum.numerator << " / " << sum.denominator << endl;


    //return the amount of all fractions
    //cout << "rncTotalCount: Zahl aller Brueche: " << rncTotalCount(c) << endl;

    //return the amount of all DIFFERENT fractions
    //cout << "rncTotalUniqueCount: verschiedenen Brueche: " << rncTotalUniqueCount(c) << endl;

    showAllNumbers(c);
    rncDelete(c);

    cout << "<-- MAIN End" << endl;
    return 0;
}
