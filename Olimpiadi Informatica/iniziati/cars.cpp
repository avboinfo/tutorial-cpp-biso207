// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);

    for (int i = 0; i < N; ++i)
        cin >> P[i];

    int K = 0;

    // INSERT YOUR CODE HERE
    bool uguali;
    vector<int> P2(P); // vettore che si modifica
    vector<int> P3(P); // vettore che di controllo ordinato
    sort(P3.begin(), P3.end());

    if (N==1) cout << 0;
    else {
        while (true) {
            K++;
            // shift di una cella i valore del vettore
            rotate(P2.rbegin(), P2.rbegin() + 1, P2.rend());

            // if di controllo
            if (P2 == P) { cout << -1; break; } // ritorno allo stato iniziale, return di K -1
            else if (P2 == P3) { cout << K; break; } // vect ordinato uguale a quello iniziale ordinato
        }
    }

    return 0;
}
