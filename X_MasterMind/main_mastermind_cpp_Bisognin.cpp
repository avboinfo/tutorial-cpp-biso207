#include <iostream>
#include <limits>
#include "mastermind.cpp"

#define RED "\e[0;31m" // colore rosso
#define NC "\e[0m"     // Nessun colore => bianco

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0, attempts = 0;
    bool stop = true;
    char scelta;

    cout << RED "MASTERMIND" NC << endl;

    mastermind gioco = mastermind();
    do {
        stop = gioco.new_attempt();

        // richiesta all'utente di riniziare di giocare o meno dopo vittoria o sconfitta
        if (!stop) {
            cout << endl << "Vuoi giocare di nuovo? [y] sì; [n] no: ";
            cin >> scelta;
            if (scelta == 'y') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                stop = true;
                gioco = mastermind();
            } else if (scelta == 'n') {
                stop = false;
            } else {
                while (scelta != 'n' && scelta != 'y') {
                    cout << "Input non valido.";
                    cout << endl << "Vuoi giocare di nuovo? [y] sì; [n] no: ";
                    cin >> scelta;
                    if (scelta == 'y') {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        stop = true;
                        gioco = mastermind();
                    }
                    else if (scelta == 'n') {
                        stop = false;
                    }
                }
            }
        }
    } while (stop);

    cout << endl << "Grazie per aver giocato!" << endl;
    return 0;
}
