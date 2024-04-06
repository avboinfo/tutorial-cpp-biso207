#include <iostream>

using namespace std;

class Ufficio {
    private:
        char scelta;
        int codice, cont_s, cont_r, cont_f;
        int pila_clienti_s[100], pila_clienti_r[100], pila_clienti_f[100];

        int servizio_s() {
            // aggiunta del cliente nella pila della fila spedizione
            ++cont_s;
            pila_clienti_s[cont_s] = cont_s;

            // rimozione del primo cliente servito
            if (cont_s%5==0) return pila_clienti_s[cont_s++];
            return 0;
        }

        int servizio_r() {
            // aggiunta del cliente nella pila della fila ricezione
            ++cont_r;
            pila_clienti_r[cont_r] = cont_r;

            // rimozione del primo cliente servito
            if (cont_r%5==0) return pila_clienti_r[cont_r++];
            return 0;
        }

        int servizio_f() {
            // aggiunta del cliente nella pila della fila finanziario
            ++cont_f;
            pila_clienti_f[cont_f] = cont_f;

            // rimozione del primo cliente servito
            if (cont_f%5==0) return pila_clienti_f[cont_f++];
            return 0;
        }

    public:
        Ufficio() {
            scelta = ' ';
            codice = 00;
            cont_s = 0;
            cont_r = 0;
            cont_f = 0;
        }

        void arrivo_utente() {
            while (true) {
                cout << "scegli il servizio\n[S] spedizione: " << cont_s << " clienti in fila"<< endl;
                cout << "[R] ricezione: " << cont_r << " clienti in fila"<< endl;
                cout << "[F] finanziario: " << cont_f << " clienti in fila" << endl;
                cin >> scelta;
                codice++;
                if (codice == 99) codice = 00;
                if (scelta == 'S') {
                    servizio_s();
                    // stampa della pila dei clienti in fila servizio
                    cout << endl << "clienti in coda servizio: " << endl;
                    for (int i=0; i<cont_s; i++) {
                        cout << pila_clienti_s[i]+1 << endl;
                        cout << "------------" << endl;
                    }
                }
                else if (scelta == 'R') {
                    servizio_r();
                    // stampa della pila dei clienti in fila ricezione
                    cout << endl << "clienti in coda ricezione: " << endl;
                    for (int i=0; i<cont_r; i++) {
                        cout << pila_clienti_r[i]+1 << endl;
                        cout << "------------" << endl;
                    }
                }
                else if (scelta == 'F') {
                    servizio_f();
                    // stampa della pila dei clienti in fila finanziario
                    cout << endl << "clienti in coda finanziario: " << endl;
                    for (int i=0; i<cont_f; i++) {
                        cout << pila_clienti_f[i]+1 << endl;
                        cout << "------------" << endl;
                    }
                }
                else { cout << "digitazione errata!\n" << endl; }
            }
        }
};