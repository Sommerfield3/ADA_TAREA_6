#include<bits/stdc++.h>
using namespace std;

int mochila2(int T,int P[],int V[],int n) {
  int K[n+1][T+1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= T; j++) {
      if (i==0 || j==0)
        K[i][j] = 0;
      else if (P[i-1] <= j)
        K[i][j] = max(V[i-1] + K[i-1][T-P[i-1]],  K[i-1][j]);
      else
        K[i][j] = K[i-1][j];
    }
  }
  return K[n][T];/*Último valor de la tabla contiene la solución*/
}

int main() {
  int V[]={100, 120, 200};
  int P[]={30, 20, 70};
  int T=70;
  int n=sizeof(V)/sizeof(V[0]);
  cout<<"Valor máximo obtenible (elementos enteros): "<<mochila2(T, P, V, n);
  return 0;
}