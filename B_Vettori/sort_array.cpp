#include <iostream>

using namespace std;

// funzione di ordinamento array secondo metodo 'bubble sort'
void bubble_sort(int array[], int len) {
    // ordinamento per metodo bubble sort
    for (int i=0; i<len-1; i++) {
        for (int j=0; j<len-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // stampa vettore
    cout << "ordinamento per bubble sort" << endl;
    for (int i=0; i<len; i++) {
        cout << array[i] << " - ";
    }
}

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;

}

int partition(int arr[], int low, int high, int pivot){
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

void quick_sort(int arr[], int low, int high){
    int len = 10, pos_1 = 0;
	if(low < high){
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        
        quick_sort(arr, low, pos-1);
        quick_sort(arr, pos+1, high);
	}
}

int main() {
    srand(time(NULL));

    int pos = 0, len = 10, array[len];

    for (int i=0; i<len; i++) {
        array[i] = rand()%20;
    }

    bubble_sort(array, len);
    quick_sort(array, 0, len-1);

    return 0;

}