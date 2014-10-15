#include <fstream>
#include <iostream>
using namespace std;

int massimo(int x, int y){
  if(x>y)
    return x;
  else
    return y;
}
	
void merge(int*array, int primo, int ultimo, int mezzo){

  int i, j, k, h;
  int arrayAppoggio[200];

  i = primo; j = mezzo+1; k = primo; 

  while (  (i<=mezzo)&&(j<=ultimo)  ){
      if(array[i]<=array[j]){
	arrayAppoggio[k]=array[i];
	i++;
      } else {
	arrayAppoggio[k]=array[j];
	j++;
      }
      
      k++;
    }

  j = ultimo;

  for(h=mezzo; h>=i; h--){
    array[j]=array[h];
    j--;
  }

  for(j=primo; j<=(k-1); j++){
    array[j] = arrayAppoggio[j];
  }
}

void mergesort(int*array, int primo, int ultimo){
  if(primo<ultimo){
    int mezzo = ((primo+ultimo)/2);
    mergesort(array, primo, mezzo);
    mergesort(array, mezzo+1, ultimo);
    merge(array, primo, ultimo, mezzo);
  }
}

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

  int array[20] = {1, 4, 5, 21, 67, 56, 243, 3432, 23, 5, 65, 67, 67, 5, 4, 234, 2354, 346};

  for(int i=0; i<20; i++){ cout << array[i] << "  ";}
  cout << endl << endl;

  mergesort(array, 0, 20);
  
  for(int i=0; i<20; i++){ cout << array[i] << "  ";}
  
  //fare mergesort, provare su array e poi iniziare a amatriciare!
  return 0;
}
