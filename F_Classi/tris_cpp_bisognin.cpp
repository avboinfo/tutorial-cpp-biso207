#include <iostream>

using namespace std;

// classe per il gioco tris

/*  grid == '+' => empty cell
    grid == 'X' => cell filled by player1
    grid == 'O' => cell filled by player2
*/
class Tris {
    // zona 'public' => i metodi e attributi sono accessibili sia dentro che fuori della classe
    public:
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
            if (x > 3 || x < 1) return false;
            if (y > 3 || y < 1) return false;
            x-=1; y-=1;
            if (grid[x][y] == 'X' || grid[x][y] == 'O') return false;

            // caso di inserimento corretto
            grid[x][y] = 'X';
            return true;

        }

        // metodo per posizionare un 'O' del player2
        bool player_two(int x, int y) {
            // casi di errore
            if (x > 3 || x < 1) return false;
            if (y > 3 || y < 1) return false;
            x-=1; y-=1;
            if (grid[x][y] == 'X' || grid[x][y] == 'O') return false;

            // caso di inserimento corretto
            grid[x][y] = 'O';
            return true;
        }

        // metodo per controllare il vincitore della partita
        int result;
        int winner() {
            for (int i=0; i<3; i++) {
                result = control_column(i);
                if (result != 0) return result;
                result = control_row(i);
                if (result != 0) return result;
                for (int j=0; j<3; j++) {
                    result = control_diagonal(i, j);
                    if (result != 0) return result;
                }
            }
        }

    // zona 'private' => i metodi e attributi sono accessibili SOLO nella classe
    private:
        // metodo per controllare che una colonna sia riempita
        int control_column(int col) {
            // accumulatori per contare i valori nelle celle di una colonna
            int acc_one = 0;
            int acc_two = 0;
            for (int i=0; i<3; i++) {
                char cell = grid[i][col];
                if (cell == 'X') acc_one++;
                else if (cell == 'O') acc_two++;
                else return 0;
            }

            if (acc_one == 3) return 1;
            if (acc_two == 3) return 2;
            return 0;

        }

        // metodo per controllare che una riga sia riempita
        int control_row(int row) {
            // accumulatori per contare i valori nelle celle di una riga
            int acc_one = 0;
            int acc_two = 0;
            for (int i=0; i<3; i++) {
                char cell = grid[row][i];
                if (cell == 'X') acc_one++;
                else if (cell == 'O') acc_two++;
                else return 0;
            }

            if (acc_one == 3) return 1;
            if (acc_two == 3) return 2;
            return 0;

        }

        // metodo per controllare che una diagonale sia riempita
        int control_diagonal(int row, int col) {
            // accumulatori per contare i valori nelle celle di una diagonale
            int acc_one = 0;
            int acc_two = 0;
            for (int i=0; i<3; i++) {
                char cell = grid[row][col];
                if (cell == 'X') acc_one++;
                else if (cell == 'O') acc_two++;
                else return 0;
            }

            if (acc_one == 3) return 1;
            if (acc_two == 3) return 2;
            return 0;
        }
};

int main() {
    
    Tris my_tris; // creiamo una variabile per richiamare i metodi della class nel main

    // init grid
    my_tris.reset_tabella();

    cout << "TRIS" << endl;
    my_tris.print_grid(); // stampa dello sta iniziale della griglia

    int x, y, cont=0, winner;
    bool valid_hit;

    // ciclo principale del gioco
    while (cont < 9) {
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

        // controllo dello stato della partita
        winner = my_tris.winner();
        if (winner != 0) break;
        
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

        // controllo dello stato della partita
        winner = my_tris.winner();
        if (winner != 0) break;
        
        cont+=2;
    }

    if (winner == 1) cout << endl << "player 1 win!" << endl;
    else if (winner == 2) cout << endl << "player 2 win!" << endl;
    else cout << "draw!" << endl;

    return 0;
}