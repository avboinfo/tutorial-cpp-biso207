/*
** prova_union.cpp
** Author: IAV 3CIN
** 26/02/2024
*/

#include <iostream>
using namespace std;

/* Il tipo di dato "union" serve per memorizzare oggetti di differenti dimensioni 
** nello stesso spazio, perciò non possono essere usati contemporaneamente.
** La struttura è grande quanto il più grande degli oggetti che può contenere.
*/

union numero
{
    int val_uno;
    float val_due;
};


int main()
{
  union numero n;
  n.val_uno = 100;
  cout <<  "1) n.val_uno = " << n.val_uno << " - " << "n.val_due = " << n.val_due << endl;
  n.val_due = 33.33;
  cout <<  "2) n.val_uno = " << n.val_uno << " - " << "n.val_due = " << n.val_due << endl;
  return 0;
}
