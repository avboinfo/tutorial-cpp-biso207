#include <vector>
#include <algorithm>

using namespace std;

int pollice_verde(int N, vector<int> H) {
    int cont = 1;

    sort(H.begin(), H.end());
    
    for (int i=0; i<N; i++) {
        if (i<N) { if (H[i] == H[i+1]) cont++; }
    }

    return cont;
}
