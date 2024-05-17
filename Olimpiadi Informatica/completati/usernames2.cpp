// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    string S;
    cin >> S;
    
    int N;
    cin >> N;
    
    vector<string> U(N);
    for (int i = 0; i < N; ++i)
        cin >> U[i];

    string T = "";
    
    
    // INSERT YOUR CODE HERE
    string base_word = S;
    int num = 1;

    for (int i=0; i<N; i++) {
        if (S==U[i]) {
            i=N;
            for (int j=0; j<N; j++) {
                if (S==U[j]) {
                    S = base_word;
                    S = S + to_string(num);
                    j=-1;
                    num++;
                }
            }
        }
    }
    T = S;
    cout << T << endl;


    return 0;
}
