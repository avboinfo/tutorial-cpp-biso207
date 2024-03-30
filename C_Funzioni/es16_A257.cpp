// Luca Bisognin - 30/03/2024 - esercizi sulla ricorsione
/* pag A257 es 16: dato un array di n interi calcolarne il numero massimo tramite una funzione ricorsiva */

#include <iostream>

using namespace std;
int MAX;
int is_max(int len, int array[]) {
    if (array[len] > array[len-1]) MAX = array[len];
    if (len == 0) return MAX;
    return is_max(len-1, array);
}

int main() {
    srand(time(NULL));
    int len = 10, array[len];

    cout << endl << "array:";
    for (int i=0; i<len; i++) {
        array[i] = rand()%100;
        cout << array[i]  << "-";
    }
    int max = is_max(len, array);

    cout << endl << "il numero maggiore dell'array è: " << max;
    return 0;
}