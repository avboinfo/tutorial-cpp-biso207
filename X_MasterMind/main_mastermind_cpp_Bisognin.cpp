#include <iostream>
#include "mastermind.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0, attempts = 0;
    bool stop = true;

    cout << endl << "MASTERMIND" << endl;

    mastermind gioco = mastermind();
    while (stop) {
        stop = gioco.new_attempt();
    }

    return 0;
}
