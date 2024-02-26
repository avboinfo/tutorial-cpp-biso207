/*
** Bicicletta.cpp
** modifiche del 26/02/2024
*/

#include <iostream>
using namespace std;

class Bicicletta {
  public:
    int raggio;
    string colore;
    // metodo costruttore privo di parametri => chiamato in automatico ogni volta che si crea un parametro della classe
    Bicicletta() {
        raggio=10;
        colore="bianco";
    }

    // metodo costruttore con parametri
    Bicicletta (int r, string c) {
        raggio = r;
        colore = c;
    }

    // metodi pubblici della classe
    void bici_base() {
        cout << endl << "la bici di fabbrica è di colore " << colore << " e con le ruote " << raggio << "." << endl;
    }
    void bici_pers() {
        cout << endl << "la bici da te creata è di colore " << colore << " e con le ruoute " << raggio << "." << endl;
    }
};

int main()
{
    Bicicletta x;
    x.bici_base();

    cout << endl << "digita le caratteristiche che vuoi che abbia la tua bici." << endl;
    int r; string c;
    cout << endl << "raggio: ";
    cin >> r;
    cout << "colore: ";
    cin >> c;

    Bicicletta y(r, c);
    y.bici_pers();

    return 0;
}
