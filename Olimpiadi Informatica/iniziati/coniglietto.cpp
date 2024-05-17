#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream stampa_file("output.txt");

    int N;
    cin >> N;
    
    vector<int> V(N);
    vector<int> V2(N);
    for (int i = 0; i < N; ++i) cin >> V[i];

    int result;
    int cont=0; // num posizioni

    for (int i=0; i<N; i++) {
        if (V[i]%N!=0) {
            cont ++;
            V2[i] = i;
        }
    }

    for (int i=0; i<N; i++) cout << V2[i];


    return 0;
}