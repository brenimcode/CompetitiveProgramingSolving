#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int n,k;


int main() {
    _

    cin >> n;
    int vet[n];

    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    cin >> k;
    
    int* maior = lower_bound(vet, vet+n, k);
    if(maior >= vet + n){
        maior--; // acessar o ultimo elemento do vetor
    }
    int j = 0;
    // Ele aponta para o primeiro cara q é maior igual a K, pego o "maior" + "menor"

    auto i = maior;

    while(true){
        
        j = 0;
        while(vet[j] <= *i){

            if(((*i) + vet[j]) == k){
                cout << vet[j] << ' ' << *i << endl;
                return 0;
            }
            if(((*i) + vet[j]) > k){
                break;
            }
            j++;

        }

        i--; // Acessar posições predecessoras
        // para que eles vao de encontro e teste todas as somas, até achar a soma == k.
    }



    return 0;
}
