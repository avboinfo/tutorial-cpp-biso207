#include <iostream>
#include "mastermind.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0;
    bool stop = true;
    mastermind gioco = mastermind();
    while (cont < 9 && stop) {
        stop = gioco.new_attempt();
        cont++;
    }

    return 0;
}