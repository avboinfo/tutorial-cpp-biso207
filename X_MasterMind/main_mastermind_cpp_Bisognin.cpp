#include <iostream>
#include "mastermind.cpp"

#define RED "\e[0;31m" // color red
#define NC "\e[0m" // No Color => white

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0, attempts = 0;
    bool stop = true;
    char scelta;

    cout << RED "MASTERMIND" NC<< endl;

    mastermind gioco = mastermind();
    while (stop) {
        stop = gioco.new_attempt();
        
        // richiesta all'utente di riniziare di giocare o meno dopo vittoria o sconfitta
        if (!stop) {
            cout << endl << "play again? [y] yes; [n] no" << endl;
            cin >> scelta;
            fflush(stdin);
            if (scelta == 'y') {
                stop = true;
                gioco = mastermind();
            }
            else if (scelta == 'n') {
                stop = false;
            }
            else if (scelta != 'n' || scelta != 'y') {
                while (scelta != 'n' || scelta != 'y') {
                    cout << endl << "invalid input! [y] yes; [n] no" << endl;
                    cin >> scelta;
                    if (scelta == 'y') {
                        stop = true;
                        gioco = mastermind();
                    }
                    else if (scelta == 'n') {
                        stop = false;
                    }
                }
            }
        }
    }

    cout << endl << "thanks for playing" << endl;
    return 0;
}
