#include <iostream>
#include "Ufficio.cpp"

using namespace std;

int main() {
    cout << endl << "BENVENUTO ALLE POSTE ITALIANE" << endl;
    Ufficio ufficio_postale = Ufficio();
    ufficio_postale.arrivo_utente();

    return 0;
}