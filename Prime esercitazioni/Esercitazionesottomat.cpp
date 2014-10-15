#include <fstream>
#include <iostream>
using namespace std;

//Funzioni
int massimo(int x, int y);
void mergesort(int*array,int primo, int ultimo, int mezzo); 

int main(){

  int righe, colonne;
  int num;
  ifstream in("input.txt");
  ofstream out("output.txt");
  //in>>righe>>colonne;
  in>> num;
  int array1[10];
  for(int i=0; i<num; i++){
    in>>array1[i];
  }

  //fare mergesort, provare su array e poi iniziare a amatriciare!
  return 0;
}

int massimo(int x, int y){
  if(x>y)
    return x;
  else
    return y;
}

void mergesort(int*array,int primo, int ultimo, int mezzo){
  int i, j, k, h;
  int arrayAppoggio[1000];

  i = primo; j = mezzo+1; k = primo; 

  while ((i<=mezzo)&&(j<=ultimo)) do{
      if(array[i]<=array[j]){
	arrayAppoggio[k]=array[i];
	i+=1;
      } else {
	arrayAppoggio[k]=array[j];
	j++;
      }
      
      k++;
    }

  j = ultimo;

  for(h=mezzo; h>i; h--){
    array[j]=array[h];
    j--;
  }

  for(j=primo; j<=(k-1); j++){
    array[j] = arrayAppoggio[j];
  }
}
