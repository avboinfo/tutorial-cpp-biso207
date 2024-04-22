/* 
Main per giocare alla Battaglia Navale
Luca Bisognin - 22/04/2024
*/

#include <iostream>

#include "BattleShip.cpp"

using namespace std;

int main() {
    cout << "BATTLESHIP" << endl;

    BattleShip gioco = BattleShip();

    gioco.play();

    cout << "THANKS FOR PLAYING\n\nDeveloped by BIGA Gaming";

    return 0;
}