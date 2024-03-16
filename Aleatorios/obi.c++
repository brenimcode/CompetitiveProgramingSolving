#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,r;
    cin >> n >> r;
    int aux1,aux2,cont=0;
    for (i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        if(aux1 + aux2 >= r){
            cont++;
        }
    }
    cout << cont;

}