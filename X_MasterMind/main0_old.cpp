/*
** MasterMind
** Classe 3CIN
** 14/5/2021
*/

#include <iostream>
#include <time.h>
using namespace std;

bool diversoDaiPrecedenti( int v[], int last ) {
    for (int i=0; i<last; i++) {
        if (v[last]==v[i]) return false;
    }
    return true;
}

void stampaVettore( int v[], int l ) {
    for (int i=0; i<l; i++) cout << v[i] << "\t";
    cout << endl;
}

int main() {

    int data[4];
    srand(time(NULL));
    for (int i=0; i<4; i++) {
        while (true) {
            data[i] = rand()%10;
            if (diversoDaiPrecedenti(data, i)) break;
        }
    }
    cout << "Programma Mastermind avviato!" << endl;
    stampaVettore(data, 4);

}