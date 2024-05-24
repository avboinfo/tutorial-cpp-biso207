// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input data
int N;
string S;

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin >> S;

    char move[29] = {'q','w', 'e', 'r','t','y','u','i','o','p','p','a','s','d','f','g','h','j','k','l','l','z','x','c','v','b','n','m','m'};
    for (int i = 0; i<N; i++){
        for (int j = 0; j<29; j++){
            if (S[i] == move[j]){
                S[i] = move[j + 1];
                break;
            }
        }
    }

    cout << S << endl; // print the result
    return 0;
}
