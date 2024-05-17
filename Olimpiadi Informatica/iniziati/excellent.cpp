// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;
    
    // insert your code here
    int cont = 0, result;
    string excellent(N, '1');

    while (cont < pow(2, N)) {

        int pos = N - 1;
        while (pos >= 0 && excellent[pos] == '5') {
            excellent[pos] = '1';
            pos--;
        }
        if (pos < 0) break;
        excellent[pos] = '5';

        cont++;

        result = stoi(excellent);
        if (result%3==0) { break; }
    }

    if (cont == pow(2, N)) result = -1;

    cout << result;

    return 0;
}
