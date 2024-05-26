#include <vector>

using namespace std;

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N){
	int cont = 0;
	for(int i=0; i<M; i++) {
		if (L[i] == 1 && D[i] == 0 && N[i] == 0) cont++;
		else if (L[i] == 0 && D[i] == 1 && N[i] == 0) cont++;
		else if (L[i] == 0 && D[i] == 0 && N[i] == 1) cont++;
	}
	int total = M-cont;
	return total;
}