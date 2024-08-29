#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    int aux;
    int vet[13];
    vector <int> result;
    for (int i = 0; i <= 13; i++)
    {
        vet[i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cin >> aux;
        vet[aux]++;  
    }
    int maisVezes = vet[0];
    for (int i = 1; i <= 12; i++)
    {
        if(vet[i] > maisVezes){
            maisVezes = vet[i];
        }
    }
    
    for (int i = 1; i <= 12; i++)
    {
        if(vet[i] == maisVezes){
            result.push_back(i);
        }
    }

    sort(result.begin(),result.end());
    for (int i = 0; i < (int) result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    
    
    cout << endl;

}