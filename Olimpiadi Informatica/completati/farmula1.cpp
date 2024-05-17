// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];
        
        string ans = "";
        
        
        // INSERT YOUR CODE HERE
        int won=0, min_won = static_cast<int>(ceil(static_cast<double>(N) / 2));
        for (int i = 0; i < N; ++i)
            if (P[i]==1) won++;

        if (won >= min_won) ans = "Champion";
        else ans = "Practice harder";
        
        
        cout << ans << endl;
    }

    return 0;
}
