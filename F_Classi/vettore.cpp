/* 
   vettore.cpp
   Classe Vettore di interi - Luca Bisognin - 4/3/2024
*/

#include <iostream>

using namespace std;

class Vettore {

    protected:
        int dim, len, delta;
        int * v;

    public:
        Vettore(int d) {
            dim = d;
            delta = 10;
            len = 0;
            v = new int(dim); // allocazione dinamica del vettore
        }

        void add(int n) {
            if (len == dim) {
                int * nuovov = new int[dim + delta];
                for (int i=0; i<dim; i++) nuovov[i] = v[i];
                dim += delta;
                v = nuovov;
            }
            v[len] = n;
            len++;
        }

        void print() {
            cout << "contenuto del vettore: ";
            for (int i=0; i<len; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    Vettore vett(10);

    for (int i=0; i<15; i++) vett.add(33+i);
    
    vett.print();

    return 0;
}