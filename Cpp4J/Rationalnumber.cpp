#include <iostream>
#include <Rationalnumber.h>
#include <assert.h>

using namespace std;

/*
int main()
{


    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);


    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );

    assert( rnLessThan( n5,n3) );


    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);
    assert( rnEqual(t1, n6) );

    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    printf(" successful!\n");

    return 0;
}*/



/*
  Vergleicht die NORMALISIERTEN Brüche miteinander
  True wenn beide gleich sind
*/
bool rnEqual(RationalNumber a, RationalNumber b)
{
    RationalNumber aNorm  = normalizeFunction(a);
    RationalNumber bNorm  = normalizeFunction(b);

    if (aNorm.numerator == bNorm.numerator && aNorm.denominator == bNorm.denominator)
    {
        cout << "Die Brueche sind gleich!" << endl;
        return true;
    }
    cout << "Die Brueche sind NICHT gleich!" << endl;
    return false;
}

/*
  Vergleicht die Brüche miteinander
  True wenn erster Bruch kleiner als der zweite Bruch
*/
bool rnLessThan(RationalNumber a , RationalNumber b)
{
    if (!rnIsValid(a) || !rnIsValid(b)){
        return false;
    }

    //wenn der nenner negativ ist negiere die Vorzeichen von Zähler und Nenner - für a
    if( a.denominator < 0 ){
        a.numerator = 0 - ( a.numerator );
        a.denominator = 0 - ( a.denominator );
    }
    //wenn der nenner negativ ist drehe die Vorzeichen rum von Zähler und Nenner - für b
    if( b.denominator < 0 ){
        b.numerator = 0 - ( b.numerator );
        b.denominator = 0 - ( b.denominator );
    }

    //Jetzt ist der Nenner garantier immer positiv dann Vergleiche die Größe des Zählers
    int c = a.numerator * b.denominator;
    int d = b.numerator * a.denominator;

    if ( c == d ){
        cout << "Beide Brüche sind gleich groß" << endl;
        return false;
    }else if ( c < d){
        cout << "Der Erste Bruch ist kleiner als der Zweite!" << endl;
        return true;
    }else{
        cout << "Der Erste Bruch ist groeser als der Zweite!" << endl;
        return false;
    }
}

/*
    Alte Funktion - ist vor Abgabe zu löschen
*/
bool rnLessThanOld(RationalNumber a , RationalNumber b)
{
    RationalNumber aNorm  = normalizeFunction(a);
    RationalNumber bNorm  = normalizeFunction(b);

    if (!rnIsValid(a) || !rnIsValid(b)){
        return false;
    }

    //int kgN = a.denominator * b.denominator;

    if( (aNorm.numerator / aNorm.denominator) < ( bNorm.numerator / bNorm.denominator) )
    {
        cout << " Ja! Der Erste Bruch ist kleiner als der Zweite! \n" << endl;
        return true;
    }else if ( (aNorm.numerator / aNorm.denominator) > ( bNorm.numerator / bNorm.denominator) )
    {
         cout << "Der Erste Bruch ist groeser als der Zweite! \n" << endl;
         return false;
    }else
    {
        cout << "Beide Brüche sind gleich \n" << endl;
        return false;
    }

}

/*
  Euklid’sche Algorithmus von http://de.wikibooks.org/wiki/C++-Programmierung/_Br%C3%BCche
*/
int normalize(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        return normalize(b, a % b);
    }
}

RationalNumber normalizeFunction(RationalNumber a)
{
    int NormalizedNum = a.numerator / normalize(a.numerator, a.denominator);
    int NormalizedDenom = a.denominator / normalize(a.numerator, a.denominator);

    RationalNumber rationalNumber = { NormalizedNum, NormalizedDenom };

    return rationalNumber;
}

/*
  Addiere zwei Brüche miteinander
  Suche erst gemeinsamen kleinsten Nenner und Addiere dann die Terme
*/
RationalNumber rnAdd(RationalNumber a, RationalNumber b)
{
    //if one of the term == 0 return the other one
    if ( a.numerator == 0 && a.denominator == 0 ){
        return b;
    }else if (b.numerator == 0 && b.denominator == 0){
        return a;
    }
    //Kleinster gemeinsamer Nenner = aNenner * bNenner
    int kgN = a.denominator * b.denominator;

    //Multipliziere Kreuzweise aNum * bDenom und aDenom * bNom
    int aNum = a.numerator * b.denominator;
    int bNum = b.numerator * a.denominator;

    RationalNumber rNr = { (aNum + bNum), kgN };

    return normalizeFunction( rNr );
}

/*
  Subtrahiere zwei Brüche miteinander
  Suche erst gemeinsamen kleinsten Nenner und Addiere dann die Terme
*/
RationalNumber rnSubtract(RationalNumber a, RationalNumber b)
{
    if ( b.numerator == 0 && b.denominator == 0 ){
        return a;
    }
    //Kleinster gemeinsamer Nenner = aNenner * bNenner
    int kgN = a.denominator * b.denominator;

    //Multipliziere Kreuzweise aNum * bDenom und aDenom * bNom
    int aNum = a.numerator * b.denominator;
    int bNum = b.numerator * a.denominator;

    RationalNumber rNr1 = { (aNum - bNum) , kgN };

    return normalizeFunction(rNr1);
}

/*
  Multipliziere Zähler mit Zähler und Nenner mit Nenner
*/
RationalNumber rnMultiply(RationalNumber a, RationalNumber b)
{
    int aBruch = a.numerator * b.numerator;
    int bBruch = a.denominator * b.denominator;
    RationalNumber rNr2 = {aBruch, bBruch};
    return rNr2;
}

/*
  Multipliziere Zähler mit Nenner und Nenner mit Zähler ÜBERKREUZ!
*/
RationalNumber rnDivide(RationalNumber a, RationalNumber b)
{
    int aBruch = a.numerator * b.denominator;
    int bBruch = a.denominator * b.numerator;
    RationalNumber rNr3 = {aBruch, bBruch};
    return rNr3;
}

bool rnIsValid(RationalNumber n)
{
    if(!n.denominator){
        return false;
    }
    return true;
}


