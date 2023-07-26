#include <bits/stdc++.h>
using namespace std;
int AuxT[10000];
int minCoins(int T,int numCoins,int coins[]){
 /* vector<int> AuxT(T);*///Memoria dinámica insuficiente para ejemplos muy grandes. Si se desea probar con ejemplos de tamaños pequeños se pued usar. en vez de la línea 3.
  for(int i = 0;i<=T;i++)
    AuxT[i]=INT_MAX;
  AuxT[0]=0;
  //Hacemos la búsqueda en la tabla
  for(int i=1;i<=T;i++){//recorrer suma
    //Para cada suma, la solución óptima
    for(int j=0;j<numCoins;j++){//Moverse a la siguiente moneda
      if(coins[j]<=i){//Si la moneda es menor o igual, que el valor de suma actual, puede agregarse a la suma
        AuxT[i]=min(AuxT[i],1+AuxT[i-coins[j]]);
      }
    }
  }
  return AuxT[T];
}

int main() {
  int coins[]={1,4,33,48,521};
  int T=1050;
  int numCoins=sizeof(coins)/sizeof(coins[0]);
  cout <<"El número mínimo de monedas para obtener el total deseado es: "<<minCoins(T,numCoins,coins);
}