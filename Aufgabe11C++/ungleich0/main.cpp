#include <iostream>
#include <header.h>

using namespace std;

int main()
{



    cout << normalize(4,6) <<endl;
    cout << normalize2(4,6) <<endl;
    return 0;


}

bool rnLessThan(RationalNumber a , RationalNumber b)
{
    int aNormalizedNum = a.numerator / normalize(a.numerator, a.denominator);
    int aNormalizedDenom = a.denominator / normalize(a.numerator, a.denominator);

    int bNormalizedNum = b.numerator / normalize(b.numerator, b.denominator);
    int bNormalizedDenom = b.denominator / normalize(b.numerator, b.denominator);

    if( (aNormalizedNum / aNormalizedDenom) < ( bNormalizedNum / bNormalizedDenom) )
    {
        cout << "Der Erste Bruch ist kleiner als der Zweite! \n" << endl;
        return true;
    }else if ( (aNormalizedNum / aNormalizedDenom) > ( bNormalizedNum / bNormalizedDenom) )
    {
         cout << "Der Erste Bruch ist groeser als der Zweite! \n" << endl;
         return false;
    }else
    {
        cout << "Beide Brüche sind gleich \n" << endl;
        return false;
    }

}

int normalize(int a, int b)
{
    if(b == 0){
        if( a == 0 ) return 1;
        else return a;
    }else{
        if(b != 0){
            return normalize(b, a % b);
        }
    }
}

int normalize2(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        return normalize(b, a % b);
    }
}
