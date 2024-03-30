// Luca Bisognin - 30/03/2024 - esercizi sulla ricorsione
/* pag A257 es 14: data una stringa s e un carattere c, calcolare le occorrenze di c in s tramite una funzione ricorsiva */

#include <iostream>
#include <string>

using namespace std;

int calc_occorrenze(char c, string s, int len) {
    if (len == 0) {
        return 0;
    }
    else if (s[len] == c) {
        return 1 + calc_occorrenze(c, s, len-1);
    }
    return calc_occorrenze(c, s, len-1);
}

int main() {
    string s; 
    char c;

    cout << "digita una stringa: ";
    getline(cin, s);
    int len = s.length();
    cout << endl << "digita un carattere per calcolarne le occorrenze in '" << s << "': ";
    cin >> c;

    int occ = calc_occorrenze(c, s, len);

    cout  << endl << "'" << c << "' è presente " << occ << " volte nella stringa '" << s << "'.";
    return 0;
}