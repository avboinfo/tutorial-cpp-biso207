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
        Vettore(int d, int delta) {
            this -> dim = d;
            this -> delta = delta;
            len = 0;
            v = new int(dim); // allocazione dinamica del vettore
        }

        void add(int n) {
            if (len == dim) {
                cout << "estendo da " << dim << " a " << dim+delta << endl;
                int * nuovov = new int[dim + delta];
                for (int i=0; i<dim; i++) nuovov[i] = v[i];
                dim += delta;
                delete v;
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

    Vettore vett(10, 2);

    for (int i=0; i<100; i++) vett.add(i);
    
    vett.print();

    return 0;
}