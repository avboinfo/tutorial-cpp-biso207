/* 
classe BattleShip per giocare alla Battaglia Navale
Luca Bisognin - 22/04/2024
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
            mappa = BattleField(WATER);
            campo = BattleField(WATER);
            // posizionamento navi sul campo di gioco e aggiornamento della mappa nascosta
            campo.place_ship_orizontal(3); // nave orizzontale di len 3 
            campo.place_ship_orizontal(4); // nave orizzontale di len 4
            campo.place_ship_vertical(2); // nave verticale di len 2
            campo.place_ship_vertical(4); // nave verticale di len 4

        }

        void play() {
            while (!game_over()) {
                mappa.stampa(); // mappa aggiornata
                if (!put_bomb()) break;
            }

            cout << endl << "GAME OVER" << endl;
            campo.stampa(); // stampa del campo con le navi nascoste mostrate
        }

        bool put_bomb() {
            // lancio di 20 bombe con coordinate inserite dall'utente
            for (int i=0; i<DIM*3; i++) {
                cout << "\ndigit coordinates " << i+1 << "/" << DIM*3 << " - (" << DIM << ", " << DIM << ") to quit\n";
                cout << "x: ";
                cin >> x;
                cout << "y: ";
                cin >> y;
                
                // controllo per quittare la partita
                if (x==DIM || y==DIM) return false;

                // controllo che le coordinate non siano sbagliate
                if (x<DIM && x>=0 && y<DIM && y>=0);
                else {
                    cout << endl << "invalid coordinates. digit again\n";
                    i--;
                    continue; // coordinata errata
                }

                // controllo delle coordinate nella mappa
                if (mappa.get(y, x) == HIT || mappa.get(y, x) == MISSED) {
                    cout << "coordinate already digitated\n";
                    i--;
                    continue; // coordinata già digitata
                }

                if (campo.get(y, x) == SHIP) { // nave colpita
                    mappa.put(y, x, HIT);
                    campo.put(y, x, SHIP_HIT);
                } else mappa.put(y, x, MISSED); // colpito il vuoto

                mappa.stampa(); // mappa aggiornata
            }

            return true;
        }

        bool game_over() {
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) {
                    if (campo.get(j, i) == SHIP) return false;
                }
            }
            return true;
        }
};