// Luca Bisognin - 25/03/2024 - esercizi sulla ricorsione in classe 
/* pag A257 es 15: 
scrivere una funzione ricorsiva c++ che assegnati due interi n ed m restituisca la somma di tutti gli interi compresi tra n ed m
*/

#include <iostream>

using namespace std;

// funzione ricorsiva per sommare i numeri compresi tra n ed m
int somma_num(int somma, int n, int m) {
    if(n<=m) {
        somma += n;
        n++;
        return somma_num(somma, n, m);
    }
    else return somma;
}

// correzione 
int somma_num_prof(int n, int m) {
    if (n>m) return 0;
    if (n==m) return m;
    return m+somma_num_prof(n, m-1);
}

int main() {
    int n, m, somma = 0;

    cout << "inserisci due numeri interi.\nn1:";
    cin >> n;
    cout << "n2:";
    cin >> m;

    somma = somma_num(somma, n, m);

    cout << "la somma dei numeri compresi tra " << n << " e " << m << " è: " << somma;

    return 0;
}