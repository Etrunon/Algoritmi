using namespace std;
#include <fstream>
#include <iostream>
#include <climits>

//Costanti
int matrice[2000][2000];
int arrIndici[2000][4];
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

void inizializza(){
  istanziaMatrice();

  for(int i=0; i<dimY; i++){
    arrIndici[i][0]=0;
    arrIndici[i][1]=0;
    arrIndici[i][2]=i;
    arrIndici[i][3]=1;
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

void stampaIndici(int sx, int sy, int fx, int fy){
  //Funzione che stampa la matrice globale ArrayDiIndici
  for(int i=sx; i<fx; i++){
   for(int j=sy; j<fy; j++){
    cout << arrIndici[i][j] << "\t\t";
  }
  cout << endl;
}
cout << endl;
}

int trovaMax(){
  //Funzione che data la matrice globale di interi ne trova l'elemento di dimensione massima
  int max = INT_MIN;

  for(int i=0; i<dimX; i++){
    for(int j=0; j<dimY; j++){
      if (max < matrice[i][j])
        max = matrice[i][j];
    }
  }

  return max;
}

bool prossimoNellaRiga(int* puntatore, int x, int y){
  bool esiste=false;

  if(x<dimX && y<dimY){
    puntatore = &matrice[x][y];
    esiste = true;
  }
  return esiste;
}

int main(){

  in >> dimX >> dimY;
  
  inizializza();

  int max = INT_MIN;
  int here;

  for(int i=0; i<dimY; i++){
    here =0;
    for(int j=0; j<dimX; j++){
      if((here+matrice[i][j])>0){
        here += matrice[i][j];
      }else{
        here =0;
      }  
      if(here>max){
        max=here;
        cout << "Nuovo here: " << here << endl;
      }
    }
      cout << "Fine riga here=" << here << endl;
  }

  return 0;
}
