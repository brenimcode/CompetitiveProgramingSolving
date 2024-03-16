#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,c,i=0,cont=0;
    cin >> n >> c;
    while(i!=n)
    {
        cont+=c;
        if(c != 1){
        c--;
        }
        i++;

    }
    cout << cont;
    
}   