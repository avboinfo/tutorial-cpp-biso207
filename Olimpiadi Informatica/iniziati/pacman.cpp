// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool chek_if_pass(int N, int X[], int Y[], int Z[]) {
    int dx, dy, dz;
    bool x = false, y = false, z = false;
    for (int i=1; i<N-1; i++) {
        dx = X[i+1] - X[i];
        dy = Y[i+1] - Y[i];
        dz = Z[i+1] - Z[i];

        if (dx == 1) x = true;
        if (dy == 1) y = true;
        if (dz == 1) z = true;

        if (!x && dx == 0) x = true;

        if (!y && dy == 0) y = true;

        if (!z && dz == 0) z = true;

        if (x && y && z) {
            x=y=z=false;
            continue;
        }
        else return false;
    }

    return true;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    int X[N];
    for (int i = 0; i < N; ++i)
        cin >> X[i];

    int Y[N];
    for (int i = 0; i < N; ++i)
        cin >> Y[i];

    int Z[N];
    for (int i = 0; i < N; ++i)
        cin >> Z[i];

    // INSERT YOUR CODE HERE
    bool success = chek_if_pass(N, X, Y, Z);
    
    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
