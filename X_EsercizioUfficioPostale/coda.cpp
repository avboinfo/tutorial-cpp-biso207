#include <iostream>

using namespace std;

class Coda {
    private:
        int size, start, stop;
        int * v;
    public:
        Coda(int size) {
            this -> size = size;
            v = new int[size];
            start = stop = 0;
        }

        void enter(int val) {
            if (stop >= size) { cout << "coda piena!"; return; }
            v[stop] = val;
            stop++;
        }

        int exit() {
            if (start >= stop) { cout << "coda vuota!"; return 0; }
            return v[start++];
        }

        void stampa() {
            cout << "elementi in coda: " << endl;
            for (int i=start; i<stop; i++) {
                cout << v[i] << endl;
                cout << "-----------------------------" << endl;
            }
        }
};

int main() {
    Coda c = Coda(1000);

    c.stampa();
    c.enter(100); 
    c.enter(120);
    c.enter(75);
    c.exit();
    c.enter(56);
    c.stampa();

    return 0;
}