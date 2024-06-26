#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define GRN "\e[0;32m" // colore verde
#define CYN "\e[0;36m" // color cyan
#define RED "\e[0;31m" // color red
#define NC "\e[0m" // No Color => white

// sconsigliato per le classi usare il namespace std per via di possibili conflitti con il main durante la compilazione
const int MAX_BUFFER_SIZE = 1024;
class mastermind {
    private:
        int attempts, strike, ball;
        std::string last_attempt;
        bool stop;

        static const int DIM_VALID_ATTEMPT = 4; // 'const' per renderlo immutabile nell'intero codice e 'static' per renderlo comune agli oggetti della classe
        int valid_attempt[DIM_VALID_ATTEMPT]; // => array di 4 celle per l'inserimento di SOLO 4 valori per tentativo
        int secret_code[DIM_VALID_ATTEMPT];

        // metodo per controllare i valori digitati dall'utente durante una giocata
        bool clear_input() {
            if (DIM_VALID_ATTEMPT != last_attempt.size()) {
                std::cout << std::endl << "invalid input, digit again" << std::endl;
                return false;
            }

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
            std::cout << std::endl << "encripted code: ****" << std::endl;
            for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                int num_random = rand()% 10; // valore minimo = 0; valore massimo = 9 => numero più piccolo = 0000; numero più grande = 9999
                secret_code[i] = num_random;
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
        bool new_attempt() {
            do {
                std::cout << std::endl << CYN "attempt "<< attempts + 1 << ": " NC;
                std::getline(std::cin, last_attempt); // il metodo getline consente di leggere anche i caratteri dopo gli spazi
            } while(!clear_input() && attempts < 9);
            attempts++;

            stop = attempt_result(attempts);

            return stop;
        }

        // metodo per confrontare il codice segreto con quello dell'utente
        bool attempt_result(int attempts) {
            strike = 0;
            ball = 0;
            for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                if (valid_attempt[i] == secret_code[i]) {
                    strike++;
                }
                else {
                    for (int j=0; j<DIM_VALID_ATTEMPT; j++) {
                        if (valid_attempt[i] == secret_code[j]) {
                            ball++;
                            valid_attempt[i] = -2;
                        }
                    }
                }
            }

            if (strike == 4) {
                std::cout << std::endl << GRN "you won! encripted code: " NC;
                for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                    std::cout << secret_code[i];
                }
                std::cout << std::endl;
                stop = false;
            }
            else {
                std::cout << "strike: " << strike << " - ball: " << ball << std::endl;
                stop = true;
            }

            if (attempts == 9 && stop) {
                std::cout << RED "you lost! encripted code: " NC;
                for (int i=0; i<DIM_VALID_ATTEMPT; i++) {
                    std::cout << secret_code[i];
                }
                std::cout << std::endl;
                stop = false;
            }

            return stop;
        }
};
