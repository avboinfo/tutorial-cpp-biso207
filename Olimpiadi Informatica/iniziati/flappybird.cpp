// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> A, B;

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    ofstream stampa("output.txt");

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i=0; i<N; i++)
        cin >> A[i] >> B[i];

    // insert your code here
    string res = "YES";
    for (int i=1; i<N; i++) {
        if (A[i+1] >= A[i] && A[i+1] <= B[i] || B[i+1] >= A[i] && B[i+1] <= B[i]);
        else { res = "NO"; break; }
    }

    cout << res << endl; // print the result
    return 0;
}
