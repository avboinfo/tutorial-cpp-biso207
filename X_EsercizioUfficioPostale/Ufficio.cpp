#include <iostream>
#include <limits>

using namespace std;

// colori per il testo
#define GRN "\e[0;32m" // colore verde
#define CYN "\e[0;36m" // color cyan
#define RED "\e[0;31m" // color red
#define NC "\e[0m" // No Color => white

class Ufficio {
    private:
        string scelta;
        char carta;
        int codice, cont_s, cont_r, cont_f, start_s, start_r, start_f;
        int pila_clienti_s[100], pila_clienti_r[100], pila_clienti_f[100];

        int servizio_s() {
            if (scelta == "S exit") {
                if (start_s >= cont_s) { return 0; }
                else {
                    cout <<RED "cliente con code " << pila_clienti_s[start_s++] << " rimosso dalla fila correttamente" NC<< endl;
                    return pila_clienti_s[start_s++];
                }
            }
            // aggiunta del cliente nella pila della fila spedizione
            cout <<GRN "sei stato inserito in coda correttamente" NC<< endl;
            pila_clienti_s[cont_s++] = codice;
            return 0;
        }

        int servizio_r() {
            if (scelta == "R exit") {
                if (start_r >= cont_r) { return 0; }
                else {
                    cout <<RED "cliente con code " << pila_clienti_r[start_r++] << " rimosso dalla fila correttamente" NC<< endl;
                    return pila_clienti_r[start_r++];
                }
            }
            // aggiunta del cliente nella pila della fila ricezione
            cout <<GRN "sei stato inserito in coda correttamente" NC<< endl;
            pila_clienti_r[cont_r++] = codice;
            return 0;
        }

        int servizio_f() {
            if (scelta == "F exit") {
                if (start_f >= cont_f) { return 0; }
                else {
                    cout <<RED "cliente con code " << pila_clienti_f[start_f++] << " rimosso dalla fila correttamente" NC<< endl;
                    return pila_clienti_f[start_f++];
                }
            }
            cout << "sei in possesso di una carta Poste Pay? [s] si, [n] no: ";
            cin >> carta;

            // controllo di una possibile digitazione errata
            while (carta != 's' && carta != 'n') {
                cout <<RED "digitazione errata" NC; 
                cin >> carta;
            }

            // controllo che l'utente abbia o meno la carta poste pay
            if (carta == 's') {
                cout << endl <<GRN "hai avuto la priorità e sei stato servito" NC<< endl;
            }
            else {
                cout << endl <<GRN "sei stato inserito in coda correttamente" NC<< endl;
                // aggiunta del cliente alla coda finanziario
                pila_clienti_f[cont_f++] = codice;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulizia buffer
            return 0;
        }

    public:
        // costruttore
        Ufficio() {
            scelta = "";
            codice = 0;
            carta = 'n';
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
                cout << "[S exit]: rimuovi l'utente che ha finito dalla fila S" << endl;
                cout << "[R exit]: rimuovi l'utente che ha finito dalla fila R" << endl;
                cout << "[F exit]: rimuovi l'utente che ha finito dalla fila F" << endl;

                cout << endl << "servizio: ";
                getline(cin, scelta);
                cout << endl;

                if (codice == 99) codice = 0; // codice identificativo del clinte per ogni servizio

                // servizio spedizione
                if (scelta == "S" || scelta == "S exit") {
                    servizio_s();
                    // stampa della pila dei clienti in fila servizio
                    if (start_s >= cont_s) cout <<RED "nessun cliente in coda spedizione" NC<< endl;
                    else cout << endl <<CYN "clienti in coda servizio:" NC<< endl;
                    for (int i=start_s; i<cont_s; i++) {
                        cout << "code: " << pila_clienti_s[i] << endl;
                        cout << "------------" << endl;
                    }
                }

                // servizio ricezione
                else if (scelta == "R" || scelta == "R exit") {
                    servizio_r();
                    // stampa della pila dei clienti in fila ricezione
                    if (start_r >= cont_r) cout <<RED "nessun cliente in coda ricezione" NC<< endl;
                    else cout << endl <<CYN "clienti in coda ricezione:" NC<< endl;
                    for (int i=start_r; i<cont_r; i++) {
                        cout << "code: " << pila_clienti_r[i] << endl;
                        cout << "------------" << endl;
                    }
                }
                
                // servizio finanziario
                else if (scelta == "F" || scelta == "F exit") {
                    servizio_f();
                    // stampa della pila dei clienti in fila finanziario
                    if (start_f >= cont_f) cout << endl <<RED "nessun cliente in coda finanziario" NC<< endl;
                    else cout << endl <<CYN "clienti in coda finanziario:" NC<< endl;
                    for (int i=start_f; i<cont_f; i++) {
                        cout << "code: " << pila_clienti_f[i] << endl;
                        cout << "------------" << endl;
                    }
                }
                else { cout <<RED "digitazione errata!\n" NC<< endl; }
                codice++;
            }
        }
};
