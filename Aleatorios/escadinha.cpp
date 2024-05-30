#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int vet[n];

    if(n == 1){
        cin >> vet[0];
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        cin >> vet[0];
        cin >> vet[1];
        cout << 1 << endl;
        return 0;
    }
    cin >> vet[0]; // lendo os 2 primeiros
    cin >> vet[1];
    int difAtual = abs(vet[0]-vet[1]);
    int sum = 1;
    for (int i = 2; i < n; i++)
    {
        cin >> vet[i];
        if(abs(vet[i] - vet[i-1]) != difAtual){
            difAtual = abs(vet[i] - vet[i-1]);
            sum++;
        }

    }
    
    cout << sum << endl;


    return 0;
}