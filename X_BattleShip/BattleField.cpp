/* 
classe BattleField per modificare e lavorare sulle matrici
Luca Bisognin - 23/04/2024
*/

#include <iostream>
#include <iomanip>

using namespace std;

#define GRN "\e[0;32m" // colore verde
#define RED "\e[0;31m" // color red
#define CYN "\e[0;36m" // color cyan
#define NC "\e[0m" // No Color => white

const int DIM = 5; // dimension of matrix 
const string HIT = (GRN " * " NC);
const string MISSED = (RED " O " NC);
const string SHIP = (RED " x " NC);
const string SHIP_HIT = (GRN " x " NC);
const string WATER = (CYN " - " NC);
const string QUIT = (NC " $ " NC);

class BattleField {
    private:
        string m[DIM][DIM];
    public:
        // primo costruttore
        BattleField(string char_m) {
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) {
                    m[i][j] = char_m;
                }
            }
        }
        // secondo costruttore
        BattleField() {
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) m[i][j] = 97 + rand()%26;
            }
        }

        // metodo per ricevere in input le coordinate della bomba
        string get(int x, int y) {
            return m[x][y];
        }

        // posizionamento della bomba sulla mappa
        void put(int x, int y, string c) {
            m[x][y] = c;
        }

        // metodo per stampare la BattleField
        void stampa() {
            // ELEMENTI GRAFICI PER MIGLIORARE LA LETTURA DELLA BattleField
            // numeri superiori e linea superiore
            cout << setw(2) << " $ |";
            for (int i=0; i<DIM; i++) cout << setw(3) << i+1;
            cout << endl;
            for (int i=0; i<DIM; i++) cout << "----";
            cout << endl;

            // stampa della BattleField
            for (int i=0; i<DIM; i++) {
                cout << setw(2) << i+1 << " |"; // stampa dei numeri laterali
                for (int j=0; j<DIM; j++) {
                    cout << setw(4) << m[i][j];
                }
                cout << " |" << endl;
            }

            // linea inferiore di chiusura BattleField
            for (int i=0; i<DIM; i++) {
                cout << "----";
            }
            cout << endl;
        }

        // metodo per piazzare le navi in verticale
        void place_ship_vertical(int len) {
            srand(time(NULL));
            int x = rand()% (DIM-len);
            int y = rand()% (DIM-len);
            for (int i=0; i<len; i++) m[x+i][y] = SHIP;
        }

        // metodo per piazzare le navi in orizzontale
        void place_ship_orizontal(int len) {
            srand(time(NULL));
            int x = rand()% (DIM-len);
            int y = rand()% (DIM-len);
            for (int i=0; i<len; i++) m[x][y+i] = SHIP;
        }
};