/*
    beecrowd | 1171
    Frequência de Números
    Adaptado por Neilor Tonin, URI  Brasil
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> par;
#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n,aux;
    set<int> numeros;
    int frequencia[2000];
    for(int i =0;i<2000;i++)
        frequencia[i] = 0;
    cin >> n;
    while(n--){
        cin >> aux; 
        if(numeros.find(aux) != numeros.end()){
            frequencia[aux]++;
        }
        else{
            // nao encontrou
            numeros.insert(aux);
            frequencia[aux]++;
        }
    }

    for(auto it = numeros.begin(); it != numeros.end() ;it++){
        cout << *it <<" aparece " << frequencia[*it] << " vez(es)"<< endl;
    }


    return 0;
}
