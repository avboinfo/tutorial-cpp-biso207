/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector> // per usare i metodi degli array (begin, end, size, resize)
#include <algorithm> // per usare il metodo sort

// constraints
#define MAXN 100000

using namespace std;

// input data
int N;
vector<int> V;

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++) cin >> V[i];

    // insert your code here
    int max, min, cont = 1;
    sort(V.begin(), V.end()); // ordinamento automatico dell'array

    for (auto item: V) {
        max = V[item];
        min = V[item+1];
        for (int j=0; j<N; j++) {
            if (max > min) {
                j=0;
                min = V[j+1];
            }
            else if (max < min) {
                j=0;
                max = V[j+1];
            }
            else {
                j--;
            }
        }
    }
    cout << min << " " << max;
    
    return 0;
}
