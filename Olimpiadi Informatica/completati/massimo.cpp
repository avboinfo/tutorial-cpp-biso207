#include <vector>
#include <algorithm>

using namespace std;

int trova_massimo(int N, vector<int> V) {
    sort(V.begin(), V.end());
    int max = V[0];
    for (int i=0; i<N; i++) {
        if (V[i] < V[i+1]) max = V[i+1];
    }

    return max;
}
