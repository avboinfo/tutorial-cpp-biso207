/*
* Calcola il fattoriale di un numero sia in modo iterativo che in modo ricorsivo
* Sandro Gallo - 8/2/2024
*/

#include <iostream>

using namespace std;

int calcoloFattorialeIterativamente( int n ) {
    int i, result;
    for (i=n, result=1; i>0; i--) result*=i;
    return result;
}

int calcoloFattorialeRicorsivamente( int n ) {
    if (n==1) return 1;
    else return n * calcoloFattorialeRicorsivamente(n-1);
}

void calcolaFattoriale( int n ) {
    cout << "Il fattoriale di " << n << " calcolato in modo iterativo è uguale a: " << calcoloFattorialeIterativamente(n) << endl;
    cout << "Il fattoriale di " << n << " calcolato in modo ricorsivo è uguale a: " << calcoloFattorialeRicorsivamente(n) << endl;
}

int main()
{
    calcolaFattoriale( 5 );
    calcolaFattoriale( 6 );
    calcolaFattoriale( 7 );
    return 0;
}
