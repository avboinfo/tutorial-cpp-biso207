#include <iostream>

using namespace std;

// classe per il gioco tris

/*  grid == '+' => empty cell
    grid == 'X' => cell filled by player1
    grid == 'O' => cell filled by player2
*/
class Tris {
    public: // permette di utilizzare gli attributi anche al di fuori della classe
        char grid[3][3]; // matrice per la griglia => atributo della classe

        // metodo per lo stato iniziale della partita o avviarne una nuova
        void reset_tabella() {
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    grid[i][j] = '+'; // riempimento della griglia di zeri
                }
            }
        }

        // metodo per stampare il contenuto della griglia ad ogni click degli utenti
        void print_grid() {
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    cout << grid[i][j] << "\t";
                }
                cout << endl;
            }
        }

        // bool per restituire lo stato delle celle => true = mossa caricata correttamente; false = mossa inserita è errata
        // metodo per posizionare la 'X' del player1
        bool player_one(int x, int y) {
            // casi di errore
            if (x > 2 || x < 0) return false;
            if (y > 2 || y < 0) return false;
            if (grid[x][y] == 'X' || grid[x][y] == 'O') return false;

            // caso di inserimento corretto
            grid[x][y] = 'X';
            return true;

        }

        // metodo per posizionare un 'O' del player2
        bool player_two(int x, int y) {
            // casi di errore
            if (x > 2 || x < 0) return false;
            if (y > 2 || y < 0) return false;
            if (grid[x][y] == 'X' || grid[x][y] == 'O') return false;

            // caso di inserimento corretto
            grid[x][y] = 'O';
            return true;
        }

};

int main() {
    
    Tris my_tris; // creiamo una variabile per richiamare i metodi della class nel main

    // init grid
    my_tris.reset_tabella();

    cout << "TRIS" << endl;
    my_tris.print_grid(); // stampa dello sta iniziale della griglia

    int x, y;
    bool valid_hit;

    // mossa del giocatore 1
    do {
        cout << endl << "player 1" << endl;
        cout << "digit valid coordinate" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        valid_hit = my_tris.player_one(x, y); // richiamo metodo per posizionare la 'X' del player 1
        if (!valid_hit) cout << "invalid coordinate or already selected" << endl;
        else cout << "valid coordinate" << endl;
    } while (!valid_hit); // negato perché nel caso di false l'utente può reinserire altri valori
    
    // stampa dello stato della griglia
    cout << endl;
    my_tris.print_grid();
    
    // mossa del giocatore 2
    do {
        cout << endl << "player 2" << endl;
        cout << "digit valid coordinate" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        valid_hit = my_tris.player_two(x, y); // richiamo metodo per posizionare la 'X' del player 1
        if (!valid_hit) cout << "invalid coordinate or already selected" << endl;
        else cout << "valid coordinate" << endl;
    } while (!valid_hit); // negato perché nel caso di false diventa true e l'utente può reinserire altri valori

    // stampa dello stato della griglia
    cout << endl;
    my_tris.print_grid();

    return 0;
}