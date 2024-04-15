#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,d,j;

    cin >> n >> d; // qtd copos, quanto danoninho pode tomar
    vector<int> vet(n,0);
    for(i =0 ;i<n;i++){
        cin >> vet[i];
    }
    int maior = 0;
    for(i =0 ;i<n;i++){
        int sum=0,qtd=0;
        for(j =0 ; j<n ;j++){
            if(sum+vet[j] <= d){
                sum+=vet[j];
                
                qtd++;
            }
        }
        if(sum <= d) {
            
            if(maior < qtd) maior = qtd;
        }

    }
    cout << maior;
    

    return 0;
}
// deve 1, 4, deve :5 , devem para ele: 3