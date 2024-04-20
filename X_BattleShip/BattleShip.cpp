/* 
classe BattleShip per giocare alla Battaglia Navale
Luca Bisognin - 20/04/2024
*/

#include <iostream>

#include "BattleField.cpp"

using namespace std;

class BattleShip {
    private:
        int x, y;
        BattleField mappa, campo;
    public:
        BattleShip() {
            mappa = BattleField('-');
            campo = BattleField(' ');
            // posizionamento navi sul campo di gioco e aggiornamento della mappa nascosta
            campo.place_ship_orizontal(3); // nave orizzontale di len 3 
            campo.place_ship_orizontal(4); // nave orizzontale di len 4
            campo.place_ship_vertical(2); // nave verticale di len 2
            campo.place_ship_vertical(4); // nave verticale di len 4

        }

        void play() {
            srand(time(NULL));
            // lancia 20 bombe a caso
            for (int i=0; i<20; i++) {
                cout << "digit coordinates " << i+1 << "/20\n";
                cout << "x: ";
                cin >> x;
                cout << "y: ";
                cin >> y;

                // controllo che le coordinate non sia sbagliate
                while (x>10 || x<0 || y>10 || y<0) {
                    cout << endl << "invalid coordinates. digit again";
                    cout << "x: ";
                    cin >> x;
                    cout << "y: ";
                    cin >> y;
                }

                // controllo delle coordinate nella mappa
                if (mappa.get(y, x) == '*' || mappa.get(y, x) == 'O') continue; // coordinata già digitata
                if (campo.get(y, x) == '-' || campo.get(y, x) == '|') { // nave colpita
                    mappa.put(y, x, '*');
                    campo.put(y, x, '*');
                } else mappa.put(y, x, 'O'); // colpito il vuoto

                mappa.stampa(); // mappa aggiornata
            }

            cout << endl << "\n- updated map - bombs dropped" << endl;
            mappa.stampa(); // mappa aggiornata
        }
};