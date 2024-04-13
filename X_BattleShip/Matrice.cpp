/* 
classe Matrice per modificare e lavorare sulle matrici
Luca Bisognin - 13/04/2024
*/

#include <iostream>

using namespace std;

class Matrice {
    private:
        int m[10][10]; // matrice 10x10

    public:
        // metodo costruttore
        Matrice(int n) {
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) m[i][j] = n;
            }
        }

        // metodo per stampare la matrice
        void stampa() {
            cout << "--------------------------------------" << endl;
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    cout << m[i][j] << " | ";
                }
                cout << endl << "--------------------------------------" << endl;
            }
        }

};

int main() {
    int n;
    cout << "caratteri matrice: ";
    cin >> n;

    Matrice m = Matrice(n);

    m.stampa();
}