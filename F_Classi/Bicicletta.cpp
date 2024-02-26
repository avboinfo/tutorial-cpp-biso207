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
    // metodo costruttore => chiamato in automatico ogni volta che si crea un parametro della classe
    Bicicletta() {
        raggio=10;
        colore="bianco";
    }

    // metodo pubblico della classe
    void presentati() {
        cout << "Buongiorno, sono una bici di colore " << colore << " e con le ruote " << raggio << "!" << endl;
    }
};

int main()
{
    Bicicletta x;

    x.presentati();

    return 0;
}
