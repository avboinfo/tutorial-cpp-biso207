/*
* Legge da un file di input un vettore di stringhe
* e produce un file di output con il vettore ordinato
* Sandro Gallo - 5/2/2024
*/

#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "SortingArray.txt";

int num_scambi, x;

void stampaVettore( string v[], int l ) {
    cout << endl;
    for (int i=0; i<l; i++) cout << v[i] << "\n";
    cout << endl;
}

void swap(string arr[] , int pos1, int pos2){
	string temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
    num_scambi++;

}

int partition(string arr[], int low, int high, string pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quick_sort(string arr[], int low, int high){
	if(low < high){
        string pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        
        quick_sort(arr, low, pos-1);
        quick_sort(arr, pos+1, high);
	}
}

int bubbleSort( string v[], int l ) {
    int numOp = 0;
    string tmp;
    for (int i=0; i<l; i++ ) {
        bool alreadySorted = true;
        for (int j=0; j<l-1; j++ ) {
            if ( v[j] > v[j+1] ) {
                alreadySorted = false;
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
            numOp++;
        }
        if (alreadySorted) break;
    }
    return numOp;
}


int main()
{
    ifstream f;
    f.open(FILENAME);
    if ( f.fail() ) { cout << "Il file di input non esiste"; return -1; }
    
    // legge tutto il file per misurarne il numero di righe
    int n;
    string s;
    for (n=0; getline(f,s); n++);
    f.close();
    cout << "il file di input contiene " << n << " righe" << endl;
    
    // rilegge il file per caricarne le righe in un vettore
    string vs[n];
    f.open(FILENAME);
    for (int i=0; i<n; i++) getline( f, vs[i] );

    cout << "array iniziale: " << endl;
    stampaVettore(vs, n);

    int scelta;
    cout << "scegli con quale metodo ordinare l'array => [1] bubble sort    [0] quick sort" << endl << "scelta: ";
    cin >> scelta;

    while (scelta > 1 || scelta < 0) {
        cout << "[error] digita => [1] bubble sort    [0] quick sort" << endl << "scelta: "; 
        cin >> scelta;
    }

    if (scelta) {
        int x = bubbleSort(vs, n);
        cout << endl << "eseguiti " << x << " scambi da 'bubble sort'." << endl;
    }
    else {
        num_scambi = 0;
        quick_sort(vs, 0, n-1);
        cout << endl << "eseguiti " << num_scambi << " scambi da 'quick sort'." << endl;
    }

    cout << "arrray ordinato:" << endl;
    stampaVettore(vs, n);

    return 0;
}
