#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,i,soma,j,aux;
    cin >> n;
    int vet[n];
    for (i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cin >> soma;
    
    for (i = 0; i < n; i++)
    {
        if(vet[i] <= soma){
            for (j = n; j > i; j--)
            {
                if(vet[j] > soma){
                    continue;
                }
                aux = vet[i] + vet[j];
                if(aux == soma){
                    cout << vet[i] << ' ' << vet[j];
                    return 0;
                }
            }
            vet[i] = soma;
            
        }
    }
    

    return 0;
}