#include <iostream>
#include "Ufficio.cpp"

using namespace std;

int main() {
    cout << "BENVENUTO ALLE POSTE ITALIANE";
    Ufficio ufficio_postale = Ufficio();
    ufficio_postale.arrivo_utente();

    return 0;
}