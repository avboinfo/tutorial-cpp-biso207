#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int pollice_verde(int N, vector<int> H) {
    int cont = 1;

    sort(H.begin(), H.end());
    
    for (int i=0; i<N; i++) {
        if (i<N) { if (H[i] == H[i+1]) cont++; }
    }

    return cont;
}

int main() {
    ifstream cin("input.txt");
    ofstream stampa("output.txt");
    int N;
    cin >> N;
    vector<int> H(N);
    for (int& i : H)
        cin >> i;

    cout << pollice_verde(N, H) << '\n';

    return 0;
}
