#include <fstream>
#include <iostream>
using namespace std;

//Funzioni
int massimo(int x, int y);

int main(){

  cout<< sizeof(int);
  int x;
  ifstream in("input.txt");
  ofstream out("output.txt");
  in>>x;

  int* p = new int[x];

  for(int i=0; i<x; i++){ //Alloco un array con dentro i numeri
    in>>p[i];
  }

  int here=0, max =0;
  for(int i=0; i<x; i++){
    here = massimo(here+p[i], 0);
    max=massimo(here, max);
  }

  out<<max;

  return 0;
}

int massimo(int x, int y){
  if(x>y)
    return x;
  else
    return y;
}
