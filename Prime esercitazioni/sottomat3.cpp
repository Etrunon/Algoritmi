using namespace std;
#include <fstream>
#include <iostream>
#include <climits>

//Costanti
int matrice[2000][2000];
int dimX, dimY;
ifstream in("input.txt");
ofstream out("output.txt");

//Funzioni
void istanziaMatrice(){
    //Funzione che riempie la matrice a scope globale con dimX e dimY valori provenienti dallo stream "in" globale
	for(int i=0; i<dimX; i++){
		for(int j=0; j<dimY; j++){
			in >> matrice[i][j];
		}
	}
}

void stampamatrice(int sx, int sy, int fx, int fy){
  //Funzione che stampa la matrice globale matrix
	for(int i=sx; i<fx; i++){
		for(int j=sy; j<fy; j++){
			cout << matrice[i][j] << "\t\t";
		}
		cout << endl;
	}
	cout << endl;
}

int massimo(int x, int y){
	if(x<y)
		return y;
	else 
		return x;
}
int colonnaMatrice(int righe, int limiteSup, int colonna){

	int x=0;
	for(int i=righe; i<limiteSup; i++){
		x+=matrice[i][colonna];
	}
	return x;

}

int main(){
	in >> dimX >> dimY;
	istanziaMatrice();
	stampamatrice(0,0,dimX, dimY);

	int max = 0;

	for(int righe=0; righe<dimY; righe++){

	int here =0;

		for(int limiteSup =0; limiteSup<dimY; limiteSup++){
			int array[dimX];

			for(int x=0; x<dimX; x++){
				array[x]= colonnaMatrice(righe, limiteSup, x);
			}

			for(int i=1; i<dimX; i++){
				here = massimo(here + array[i], 0);
				max = massimo(here, max);
				cout << "Cambio max: " << max << endl;
			}
		}
	}
	cout << max;
}
