#include <bits/stdc++.h>

using namespace std;

int main(){
    int sum,n,best;
    cin >> n;
    int vet[n];
    sum = vet[0];
    best = vet[0];
    for (int i = 1; i < n; i++)
    {
       // Atualiza 'sum' com o máximo entre iniciar um novo
       // subarray em array[i] ou continuar o subarray atual
        sum = max(vet[i], sum + vet[i]);
        
        // Atualiza 'best' se 'sum' atual for maior
        best = max(best, sum);
    }
    
    cout << best << "\n"; // Imprime a maior soma de subarray encontrada

}