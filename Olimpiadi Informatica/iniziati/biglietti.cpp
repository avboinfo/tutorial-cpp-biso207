#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int compra(int N, int M, int A, int B) {
    int price_carnet;
    int price_sing = N*A;
    
    if (B<price_sing) cout << "muori";
    else return price_sing;
    


    return price_carnet;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("biglietti.input1.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
