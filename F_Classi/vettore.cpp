/* 
   vettore.cpp
   Classe Vettore di interi - Luca Bisognin - 4/3/2024
*/

// protected: attributi e metodo richiamabili in questa classe e nelle sue derivate
// private: attributi e metodi richiamabili SOLO nella loro classe
// public: attributi e metodi richiamabili nella classe, nelle sue derivate e nel main

#include <iostream>

using namespace std;

// information hiding (incapsulamento)
// gli OOP hanno tutti questa caratteristica di poter nascondere attributi e informazioni, ed è una delle 3 caratteristiche delle classi

class Vettore {

    protected:
        int dim, len, delta;
        int * v;

    public:
        Vettore(int d, int delta) {
            this -> dim = dim;
            this -> delta = delta;
            len = 0;
            v = new int(dim); // allocazione dinamica del vettore
        }

        void add(int n) {
            if (len == dim) {
                //cout << "estendo da " << dim << " a " << dim+delta << endl;
                int * nuovov = new int[dim + delta];
                for (int i=0; i<dim; i++) nuovov[i] = v[i];
                dim += delta;
                delete v;
                v = nuovov;
            }
            v[len] = n;
            len++;
        }

        // metodo per conoscere il valore nella posizione 'index'
        int get_element(int index) {
            return v[index];
        }

        // metodo per cambiare il valore presente nella posizione 'index'
        void set_element(int index, int element) {
            v[index] = element;
        }

        void print() {
            cout << endl << "contenuto del vettore" << endl;
            for (int i=0; i<len; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    Vettore vett(10, 2);

    for (int i=0; i<100; i++) vett.add(i);

    // i getter e i setter sono i metodi per leggere e modificare gli attributi privati di una classe
    cout << vett.get_element(10) << endl;
    vett.set_element(10, 333);
    
    vett.print();

    return 0;
}