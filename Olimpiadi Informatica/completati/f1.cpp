// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> H, V;

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    // insert your code here
    int min_H = H[0], min_V = V[0], sum_H=0, sum_V=0;
    for (int i=0; i<N; i++) {
        if (H[i] < min_H) min_H = H[i]; // fastest hamilton
        if (V[i] < min_V) min_V = V[i]; // fastest verstappen

        sum_H += H[i]; // tempo totale hamilton
        sum_V += V[i]; // tempo totale verstappen
    }

    string winner = "", fastest = "";
    if (sum_H < sum_V) winner = "Hamilton";
    else winner = "Verstappen";

    if (min_H < min_V) fastest = "Hamilton";
    else fastest = "Verstappen";

    cout << winner << endl << fastest;

    return 0;
}
