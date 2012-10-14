#include <iostream>
#include <header.h>
#include <assert.h>

using namespace std;

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
    RationalNumber aNorm  = normalizeFunction(a);
    RationalNumber bNorm  = normalizeFunction(b);

    if (!rnIsValid(a) || !rnIsValid(b)){
        return false;
    }

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

    //Kleinster gemeinsamer Nenner = aNenner * bNenner
    int kgN = a.denominator * b. denominator;

    //Multipliziere Kreuzweise aNum * bDenom und aDenom * bNom
    int aNum = a.numerator * b.denominator;
    int bNum = b.numerator * a.denominator;

    //Normalisiere die Terme nochmal - nicht zwingend notwendig
    //Fkt normalize ermittelt den größten gemeinsamen Nenner!
    int NormalizedNum = (aNum + bNum) / normalize(aNum+bNum, kgN);
    int NormalizedDenom = kgN / normalize(aNum+bNum, kgN);

    cout << "AddierterTerm: " << aNum+bNum << " / " << kgN << endl;
    cout << "Addierter Term normalisiert: " << NormalizedNum << " / " << NormalizedDenom << endl;

    RationalNumber rNr = {NormalizedNum, NormalizedDenom};

    return rNr;
}

RationalNumber rnSubtract(RationalNumber a, RationalNumber b)
{
    //Kleinster gemeinsamer Nenner = aNenner * bNenner
    int kgN = a.denominator * b. denominator;

    //Multipliziere Kreuzweise aNum * bDenom und aDenom * bNom
    int aNum = a.numerator * b.denominator;
    int bNum = b.numerator * a.denominator;

    //Normalisiere die Terme nochmal - nicht zwingend notwendig
    //Fkt normalize ermittelt den größten gemeinsamen Nenner!
    int NormalizedNum = (aNum - bNum) / normalize(aNum, bNum);
    int NormalizedDenom = kgN / normalize(aNum, bNum);

    cout << "AddierterTerm: " << aNum - bNum << " / " << kgN << endl;
    cout << "Addierter Term normalisiert: " << NormalizedNum << " / " << NormalizedDenom << endl;

    RationalNumber rNr1 = {NormalizedNum, NormalizedDenom};

    return rNr1;
}

/*
  Multipliziere Zähler mit Zähler und Nenner mit Nenner
*/
RationalNumber rnMultiply(RationalNumber a, RationalNumber b)
{
    int aBruch = a.numerator * b.numerator;
    int bBruch = a.denominator * b.denominator;
    RationalNumber rNr2 = {aBruch, bBruch};
    cout << "Ergebnis der Multiplikation: "<< aBruch << " / " << bBruch << endl;
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
    cout << "Ergebnis der Division: "<< aBruch << " / " << bBruch << endl;
    return rNr3;
}

bool rnIsValid(RationalNumber n)
{
    if(!n.denominator){
        return false;
    }
    return true;
}


