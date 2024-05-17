#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

#define MAXN 100000

int zeri(int N, char S[]) {
    // moltiplicazione dei valori
    int risultato = 1;
    char* token = strtok(S, "x");
    while (token != NULL) {
        int numero = atoi(token); // Converti la sottostringa in intero
        risultato *= numero; // Moltiplica il risultato per il numero
        token = strtok(NULL, "x"); // Passa al prossimo token
    }
    string str_result = to_string(risultato);
    long long arr_result[MAXN]; // array del risultato
    long long len = str_result.size();
    for (int i = 0; i < len; ++i) {
        arr_result[i] = str_result[i] - '0'; // Converte il carattere in intero
    }

    int cont=0;
    for (int i=len; i>0; i--) {
        if (arr_result[i] == 0) cont++; 
        else break;
    }
    return cont-1;
}


char S[MAXN + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", zeri(strlen(S), S));
    fclose(fr);
    fclose(fw);

    return 0;
}
