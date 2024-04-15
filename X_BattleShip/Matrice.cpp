/* 
classe Matrice per modificare e lavorare sulle matrici
Luca Bisognin - 15/04/2024
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int DIM = 10;

class Matrice {
    private:
        char m[DIM][DIM];
    public:
        // primo costruttore
        Matrice(char char_m) {
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) m[i][j] = char_m;
            }
        }
        // secondo costruttore
        Matrice() {
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) m[i][j] = 97 + rand()%26;
            }
        }

        // metodo per ricevere in input le coordinate della bomba
        char get( int x, int y ) {
        return m[x][y];
        }
        // posizionamento della bomba sulla mappa
        void put( int x, int y, char c ) {
            m[x][y] = c;
        }

        // metodo per stampare la matrice
        void stampa() {
            // ELEMENTI GRAFICI PER MIGLIORARE LA LETTURA DELLA MATRICE
            // numeri superiori e linea superiore
            cout << setw(4) << "x |";
            for (int i=0; i<DIM; i++) cout << setw(4) << i;
            cout << endl;
            for (int i=0; i<DIM; i++) cout << "-----";
            cout << endl;

            // stampa della matrice
            for (int i=0; i<DIM; i++) {
                cout << setw(2) << i << " |"; // stampa dei numeri laterali
                for (int j=0; j<DIM; j++) {
                    cout << setw(4) << m[i][j];
                }
                cout << " |" << endl;
            }

            // linea inferiore di chiusura matrice
            for (int i=0; i<DIM; i++) {
                cout << "-----";
            }
            cout << endl;
        }

        // metodo per lanciare una bomba e disegnare una x sulla coordinata scelta
        void bomb() {
            int x = rand()% DIM;
            int y = rand()% DIM;
            m[x][y] = 'X';
        }

        // metodo per piazzare le navi in verticale
        void place_ship_vertical(int len) {
            int x = rand()% (DIM-len);
            int y = rand()% (DIM-len);
            for (int i=0; i<len; i++) m[x+i][y] = 'O';
        }

        // metodo per piazzare le navi in orizzontale
        void place_ship_orizontal(int len) {
            int x = rand()% (DIM-len);
            int y = rand()% (DIM-len);
            for (int i=0; i<len; i++) m[x][y+i] = 'O';
        }
};

int main() {
    srand(time(NULL));
    // ~ = 126
    Matrice mappa = Matrice('-'); // mappa iniziale
    Matrice campo = Matrice(' '); // mappa nascosta

    cout << "- initial map -" << endl;
    mappa.stampa(); // stampa mappa iniziale

    // posizionamento navi sul campo di gioco
    campo.place_ship_orizontal(3); // mappa aggiornata
    campo.place_ship_orizontal(4); // mappa aggiornata
    campo.place_ship_vertical(2); // mappa aggiornata
    campo.place_ship_vertical(4); // mappa aggiornata

    cout << endl << "- updated map -" << endl;
    campo.stampa(); // mappa aggiornata
    
    // lancia 20 bombe a caso
    for (int i=0; i<20; i++) {
        int x = rand() % DIM;
        int y = rand() % DIM;
        if (campo.get(x,y)=='O') mappa.put(x,y,'*');
    }

    return 0;
}