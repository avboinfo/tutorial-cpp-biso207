// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    int min = P[0], K = 0, lastElement = 0;


    //calcolo minimo nel vettore
    for(int i = 1; i < N; i++) if(P[i] < min) min = P[i];
   
    //giro il vettore finchè il più piccolo è il primo
    while(P[0] != min){
        rotate(P.rbegin(), P.rbegin() + 1,P.rend());
        K++;
    }
   
    int cont = 0;

    //è ordinato?
    bool ordinato = is_sorted(P.begin(), P.end());
    if(!ordinato) K = -1;

    cout << K << endl;

    return 0;
}
