#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ll N,x;
    cin >> N;
    vector<ll>v;
    while(N--){
        cin >> x;
        v.push_back(x);
    }
    ll produto,maior=0;
    for(ll i=0;i<v.size();i++){
        if(v[i]<0 && v[i+1]<0) produto = v[i] * v[i+1] * v[v.size()-1];  
        else produto = v[i] * v[i+1] * v[i+2];
        if(produto > maior) maior = produto;
    }
    cout << maior << endl;
}
