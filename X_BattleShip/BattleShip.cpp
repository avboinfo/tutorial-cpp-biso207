/* 
classe BattleShip per giocare alla Battaglia Navale
Luca Bisognin - 23/04/2024
*/

#include <iostream>

#include "BattleField.cpp"

using namespace std;

class BattleShip {
    private:
        int x, y, i;
        bool win;
        BattleField mappa, campo;
    public:
        BattleShip() {
            i=0;
            win = false;
            mappa = BattleField(WATER);
            campo = BattleField(WATER);
            // posizionamento navi sul campo di gioco e aggiornamento della mappa nascosta
            campo.place_ship_orizontal(3); // nave orizzontale di len 3 
            campo.place_ship_orizontal(4); // nave orizzontale di len 4
            campo.place_ship_vertical(2); // nave verticale di len 2
            campo.place_ship_vertical(4); // nave verticale di len 4
        }

        void play() {
            cout << endl;
            mappa.stampa();
            while (!game_over() && i<DIM*3) {
                int result = put_bomb(i);
                if (result == 1) break; // quit
                else if (result == 2) {
                    cout << endl << "invalid coordinates" << endl; // inserite coordinate invalide
                    cout << "digit again!" << endl;
                }
                else if (result == 3) {
                    cout << endl << "coordinates already digitated" << endl; // coordinate già inserite
                    cout << "digit again!" << endl;
                }
                else { i++; cout << endl; mappa.stampa(); } // mappa aggiornata 
            }

            if (win) cout << endl << "YOU WON!" << endl;
            else cout << endl << "GAME OVER" << endl;
            cout << endl;
            campo.stampa(); // stampa del campo con le navi nascoste mostrate
        }

        int put_bomb(int i) {
            // lancio di 20 bombe con coordinate inserite dall'utente
            cout << "\ndigit coordinates " << i+1 << "/" << DIM*3 << " - (" << DIM+1 << ", " << DIM+1 << ") to quit\n";
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            
            // controllo per quittare la partita
            if (x==DIM+1 && y==DIM+1) return 1;

            // controllo che le coordinate non siano sbagliate => coordinate invalide return 2
            if (x>DIM || x<=0 || y>DIM || y<=0) return 2;
            else { x--; y--; } 

            // controllo che le coordinate non siano già state digitate
            if (mappa.get(y, x) == HIT || mappa.get(y, x) == MISSED) return 3;

            if (campo.get(y, x) == SHIP) { // nave colpita
                mappa.put(y, x, HIT);
                campo.put(y, x, SHIP_HIT);
            } else mappa.put(y, x, MISSED); // colpito il vuoto

            return 0;
        }

        bool game_over() {
            
            for (int i=0; i<DIM; i++) {
                for (int j=0; j<DIM; j++) {
                    if (campo.get(j, i) == SHIP) return false;
                }
            }

            win = true;
            return true;
        }
};