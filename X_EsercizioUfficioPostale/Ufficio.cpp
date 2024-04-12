#include <iostream>
#include <limits>

using namespace std;

class Ufficio {
    private:
        string scelta;
        int codice, cont_s, cont_r, cont_f, start_s, start_r, start_f;
        int pila_clienti_s[100], pila_clienti_r[100], pila_clienti_f[100];

        int servizio_s() {
            if (scelta == "S exit") {
                return pila_clienti_s[start_s++];
            }
            // aggiunta del cliente nella pila della fila spedizione
            pila_clienti_s[cont_s++] = codice;
            return 0;
        }

        int servizio_r() {
            if (scelta == "R exit") {
                return pila_clienti_r[start_r++];
            }
            // aggiunta del cliente nella pila della fila ricezione
            pila_clienti_r[cont_r++] = codice;
            return 0;
        }

        int servizio_f() {
            if (scelta == "F exit") {
                return pila_clienti_f[start_f++];
            }
            // aggiunta del cliente nella pila della fila finanziario
            pila_clienti_f[cont_f++] = codice;
            return 0;
        }

    public:
        Ufficio() {
            scelta = "";
            codice = 00;
            cont_s = cont_r = cont_f = 0;
            start_s = start_r = start_f = 0;
        }

        void arrivo_utente() {
            while (true) {
                cout << endl << "scegli il servizio" << endl;
                cout << "[S] spedizione: " << cont_s << " clienti in fila"<< endl;
                cout << "[R] ricezione: " << cont_r << " clienti in fila"<< endl;
                cout << "[F] finanziario: " << cont_f << " clienti in fila" << endl;
                cout << endl;
                cout << "[S] exit: rimuovi il primo utente dalla fila S" << endl;
                cout << "[R] exit: rimuovi il primo utente dalla fila R" << endl;
                cout << "[F] exit: rimuovi il primo utente dalla fila F" << endl;
                getline(cin, scelta);
                if (codice == 99) codice = 0;
                if (scelta == "S" || scelta == "S exit") {
                    servizio_s();
                    // stampa della pila dei clienti in fila servizio
                    cout << endl << "clienti in coda servizio" << endl;
                    for (int i=start_s; i<cont_s; i++) {
                        cout << "code: " << pila_clienti_s[i] << endl;
                        cout << "------------" << endl;
                    }
                }
                else if (scelta == "R" || scelta == "R exit") {
                    servizio_r();
                    // stampa della pila dei clienti in fila ricezione
                    cout << endl << "clienti in coda ricezione" << endl;
                    for (int i=start_r; i<cont_r; i++) {
                        cout << "code: " << pila_clienti_r[i] << endl;
                        cout << "------------" << endl;
                    }
                }
                else if (scelta == "F" || scelta == "F exit") {
                    servizio_f();
                    // stampa della pila dei clienti in fila finanziario
                    cout << endl << "clienti in coda finanziario" << endl;
                    for (int i=start_f; i<cont_f; i++) {
                        cout << "code: " << pila_clienti_f[i] << endl;
                        cout << "------------" << endl;
                    }
                }
                else { cout << "digitazione errata!\n" << endl; }
                codice++;
            }
        }
};