/* 
Main per giocare alla Battaglia Navale
Luca Bisognin - 23/04/2024
*/

#include <iostream>

#include "BattleShip.cpp"

using namespace std;

int main() {
    cout << "BATTLESHIP" << endl;

    BattleShip gioco = BattleShip();

    gioco.play();

    cout << "\nTHANKS FOR PLAYING\n\nDeveloped by BIGA Gaming\n";

    return 0;
}