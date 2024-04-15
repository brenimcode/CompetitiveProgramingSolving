#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i;

    cin >> n;
    int vet1[n],vet2[n];

    for(i =0 ;i<n;i++){
        cin >> vet1[i];
    }

    for(i =0 ;i<n;i++){
        cin >> vet2[i];
    }    
    int recebe = 0,paga=0;
    for(i =0 ;i<n;i++){
        if(vet1[i]>vet2[i]){
                recebe+= vet1[i] - vet2[i];
        }
        else{
            paga+= vet2[i] - vet1[i];
        }
    }    
    cout << recebe << ' ' <<paga << endl;
    return 0;
}
// deve 1, 4, deve :5 , devem para ele: 3