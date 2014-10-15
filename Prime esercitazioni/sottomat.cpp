using namespace std;
#include <fstream>
#include <iostream>
#include <climits>

//Tipi
enum Direzioni {Su, Giu, Sinistra, Destra};
enum Diagonali {SuSx, SuDx, GiuSx, GiuDx};
//Costanti
int matrice[2000][2000];
int dimX, dimY;
ifstream in("input.txt");
ofstream out("output.txt");

int piccolaX, piccolaY, passoCrescita, passoDistruzione;

Direzioni crescitaDir = Su;
Diagonali crescitaDia = SuSx;

//Funzioni
void istanziaMatrice(){
    //Funzione che riempie la matrice a scope globale con dimX e dimY valori provenienti dallo stream "in" globale
  for(int i=0; i<dimX; i++){
    for(int j=0; j<dimY; j++){
      in >> matrice[i][j];
    }
  }
}

void stampamatrice(){
  //Funzione che stampa la matrice globale matrix
  for(int i=0; i<dimX; i++){
   for(int j=0; j<dimY; j++){
    cout << matrice[i][j] << " ";
  }
  cout << endl;
}

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

int crescita(Direzioni direzione){
  //Funzione che ritorna gli indici della crescita possibile in alto basso o laterale. Fa anche i controlli per
  //  verificare che gli indici sono interni alla matrice stessa.

  int indice;

  if( direzione==Su || direzione==Giu){
    indice=piccolaY;
  }else{
    indice=piccolaX;
  }

//DEBUG
  cout << indice << endl;
  cout << passoCrescita << " <- passoCrescita :/ Fuori dal ciclo" << endl;

  switch(direzione){
    case Su  : {
                  indice=piccolaY-passoCrescita;
                  cout << indice << "calcolato con il passo" << endl;
                  if(indice<0){
                    cout << "L'indice era minore della matrice" << endl;
                    indice=0;
                  }
                };
      break;
    case Giu : {
                  indice = piccolaY+passoCrescita;
                  if(indice>dimY){
                  indice=dimY;
                  }
                }; break;
    case Sinistra : {
                      indice=piccolaX-passoCrescita;
                      cout << indice << "calcolato con il passo" << endl;
                      if(indice<0){
                        indice=0;
                      }
                    }; break;
    case Destra : {
                      indice=piccolaX+passoCrescita;
                      cout << indice << "calcolato con il passo" << endl;
                      if(indice>dimX){
                        indice=0;
                      }
                  }; break;
    }           
  
  cout << indice;
  return indice;
}

int main(){

  in >> dimX >> dimY;
  
  istanziaMatrice();
  stampamatrice(); 

  passoCrescita = 1;
  piccolaY = 4; 
  piccolaX = 4; 

  crescita(Giu);

  return 0;
}
