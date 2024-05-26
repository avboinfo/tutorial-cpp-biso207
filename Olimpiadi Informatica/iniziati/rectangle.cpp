// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // per usare il metodo sort

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    ofstream stampa("output.txt");

    int N;
    cin >> N;
    
    vector<int> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    
    long long A = 0;
    
    
    // INSERT YOUR CODE HERE
    sort(S.begin(), S.end(), greater<int>());
    vector<int> double_num(N);
    int cont=0;

    for (int i = 0; i < N; i++) {
        cout << S[i] << endl;
        if (S[i] == S[i+1]) cont++;
        if (cont >= 2) { double_num[i] = S[i]; cont=0; }
    }
    
    for (int i=0; i<N; i++) {
        cout << double_num[i] << endl;
    }

    cout << A << endl;

    return 0;
}
