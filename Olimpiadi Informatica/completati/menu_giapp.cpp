#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream cin("input0.txt");
    ofstream stampa("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    // codice
    sort(P.begin(), P.end(), greater<int>());
    for (int i=0; i<N; i++) {
        if (P[i] + P[i+1] <= K) { cout << P[i] << endl << P[i+1]; break; }
    }
    
    return 0;
}