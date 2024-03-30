#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int32_t main(){
    ll n,k,i;
    cin >> n >> k;
    vector <ll> vet;
    ll aux;
    for(i=0;i<n;i++){
        cin >> aux;
        vet.push_back(aux);
    }

    sort(vet.begin(),vet.end());
    ll result = 0;
    ll qtd = 0;

    while(1){

        if(qtd%2 == 0){
            result += vet[n-1]; //aqui ele soma com o maior elemento
        }
        else{
            result += vet[n-2];
        }
        qtd++;
        if(result >= k){
            cout << qtd << endl;
            break;
        }


    }


return 0;
}
