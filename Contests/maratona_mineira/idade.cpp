#include <bits/stdc++.h>

using namespace std;




int main(){
    int n,aux,i;
    stack < int> pilha;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> aux;
        if(aux == 0)
            pilha.pop();
        if(aux != 0)
            pilha.push(aux);
    }
    int sum=0;
    while(!pilha.empty()){
        sum += pilha.top();
        pilha.pop();
    }

    cout << sum;




    return 0;
}
