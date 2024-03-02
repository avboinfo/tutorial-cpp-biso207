#include <iostream>
#include "mastermind.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    int cont = 0;
    mastermind gioco = mastermind();
    while (cont < 9) {
        gioco.new_attempt();
        cont++;
    }

    return 0;
}