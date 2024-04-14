#include <bits/stdc++.h>

using namespace std;

#define NMAX 1010


int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector <int> fila;
    fila.push_back(a); fila.push_back(b); fila.push_back(c); fila.push_back(d);
   sort(fila.begin(),fila.end());

    int menor = abs(fila[3]+fila[0] - (fila[2]+fila[1]));
    
    cout << menor;



}
