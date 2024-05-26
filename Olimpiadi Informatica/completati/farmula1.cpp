// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    ofstream stampa("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        int cont = 0;
        
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        string ans = "";
        
        
        // INSERT YOUR CODE HERE
        bool won = false;

        for (int i = 0; i < N; i++) {
            if (P[i] == 1) cont++;
        }

        int num = N/2;
        cout << num;

        if (cont >= num) won = true;

        if (won) cout << "Champion";
        else cout << "Practice harder";
    }

    return 0;
}
