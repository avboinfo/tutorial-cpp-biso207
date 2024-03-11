/* 
   stack.cpp
   Classe Stack di interi - Luca Bisognin - 11/3/2024
*/

#include <iostream>

using namespace std;

// push inserisce valore nello stack
// pop rimuove dall'ultimo elemento dallo stack un valore alla volta
// la tecnica di salvataggio e rimozione usata è detta LIFO (Last-In-First-Out)

class Stack {

    protected:
        int dim, len, delta;
        int * v;

    public:
        Stack(int d, int delta) {
            this -> dim = dim;
            this -> delta = delta;
            len = 0;
            v = new int(dim); // allocazione dinamica della stack
        }

        void push(int n) {
            if (len == dim) {
                int * nuovov = new int[dim + delta];
                for (int i=0; i<dim; i++) nuovov[i] = v[i];
                dim += delta;
                delete[] v;
                v = nuovov;
            }
            v[len] = n;
            len++;
        }

        int pop() {
            if (len == 0) {
                cout << endl << "ERRORE -> stack terminato";
                return 1;
            }
            return v[--len];
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
            for (int i=0; i<len; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    Stack stack(10, 2);

    for (int i=0; i<100; i++) stack.push(i);

    cout << stack.get_element(10) << endl;
    //stack.set_element(10, 333);
    
    cout << endl << "elementi nello stack" << endl;
    stack.print();

    cout << endl << "elementi rimossi dallo stack" << endl;
    for (int i=0; i<101; i++) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    cout << endl << "elementi rimanenti nello stack" << endl;
    stack.print();

    return 0;
}