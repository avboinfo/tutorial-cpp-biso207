#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// sconsigliato per le classi usare il namespace std per via di possibili conflitti con il main durante la compilazione

class mastermind {
    private:
        int attempts, strike, ball;
        std::string last_attempt;

        static const int DIM_VALID_ATTEMPT = 4; // 'const' per renderlo immutabile nell'intero codice e 'static' per renderlo comune agli oggetti della classe
        int valid_attempt[DIM_VALID_ATTEMPT]; // => array di 4 celle per l'inserimento di SOLO 4 valori per tentativo
        
        int secret_code[DIM_VALID_ATTEMPT];

        // metodo per controllare i valori digitati dall'utente durante una giocata
        bool clear_input() {
            if (DIM_VALID_ATTEMPT != last_attempt.size()) {
                std::cout << std::endl << "invalid input, digit again" << std::endl;
                return false;
            }
            int j=0;

            for (int i=0; i<last_attempt.size(); i++) {
                char c = last_attempt[i];
                if (c >= '0' && c <= '9') {
                    // input valido e salvato
                    valid_attempt[i] = c - '0';
                }
                else if (c == '-') {
                    valid_attempt[i] = -1;
                }
                else {
                    std::cout << std::endl << "invalid input, digit again" << std::endl;
                    return false;
                }
            }
            return true;
        }

        // metodo per generare il codice segreto
        void generate_secret_code() {
            srand(time(NULL));  
            for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                secret_code[i] = rand()% 10; // valore minimo = 0; valore massimo = 9 => numero più piccolo = 0000; numero più grande = 9999
            }
        }

    public:
        // metodo costruttore
        mastermind() {
            attempts = 0;
            last_attempt = "";
            strike = 0;
            ball = 0;
            // creazione del codice segreto
            generate_secret_code();
        }

        // metodo per inserire una nuova giocata
        void new_attempt() {
            do {
                std::cout << std::endl << "attempt " << attempts + 1 << ": ";
                std::getline(std::cin, last_attempt); // il metodo getline consente di leggere anche i caratteri dopo gli spazi
            } while(!clear_input());
            attempts++;
            attempt_result();
        }

        // metodo per confrontare il codice segreto con quello dell'utente
        void attempt_result() {
            strike = 0;
            ball = 0;
            for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                for (int j=0; j<DIM_VALID_ATTEMPT; j++) {
                    if (valid_attempt[i] == secret_code[j]) {
                        ball++;
                    }
                }
                if (valid_attempt[i] == secret_code[i]) {
                    strike++;
                }
            }
            if (strike == 4) {
                std::cout << std::endl << "strike: " << strike << " - ball: " << ball << std::endl;
            }
            std::cout << std::endl << "strike: " << strike << " - ball: " << ball << std::endl;
        }
    };
