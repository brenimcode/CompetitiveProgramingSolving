#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i;
    cin >> n;
    int vet[n];
    for ( i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    for ( i = 1; i < n-1; i++)
    {
        if(vet[i]< vet[i-1] && vet[i] < vet[i+1]){
            cout << 'S';
            return 0;
        }
    }

    cout << 'N';
  
}   