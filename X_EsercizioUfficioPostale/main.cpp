#include <iostream>
#include "Ufficio.cpp"

// colori per il testo
#define RED "\e[0;31m" // color red
#define NC "\e[0m" // No Color => white

using namespace std;

int main() {
    cout << RED "BENVENUTO ALLE POSTE ITALIANE" NC << endl;
    Ufficio ufficio_postale = Ufficio();
    ufficio_postale.arrivo_utente();

    return 0;
}
