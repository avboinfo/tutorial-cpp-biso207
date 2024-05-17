// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, P;
    cin >> N >> P;
    
    vector<array<int, 3>> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i][0] >> S[i][1] >> S[i][2];
    }

    // insert your code here
    int sum, sum2, S2[N-1], result;

    sum = S[0][0] + S[0][1] + S[0][2];

    // aggiunta in un array dei massimi risultati fattibili dalle altre squadre
    for (int i=0; i<N; i++) {
        sum2 = (S[i+1][0] + S[i+1][1] + S[i+1][2] + (100*P));
        S2[i] = sum2;
    }

    int max = S2[0];

    // controllo del numero maggiore
    for (int i=0; i<N-1; i++) {
        if (max < S2[i]) { 
            max = S2[i]; 
        }
    }

    if (sum <= max) { 
        result = (max-sum)+1; 
    }
    else result = 0;

    cout << result << endl; // print the result
    
    return 0;
}
