#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,aux;
    int total=0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> aux;
        total |= aux;
    }
    cout << total;
    
}