// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    ofstream s("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    
    int ans = 0;
    
    
    // INSERT YOUR CODE HERE
    int avg = N*K;

    cout << ans;

    return 0;
}
