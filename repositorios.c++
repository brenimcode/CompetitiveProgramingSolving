#include <bits/stdc++.h> // biblioteca magica
#include <iostream>

using namespace std;

int main(){
    int c,n,j,i;
    cin >> c >> n;
    pair <int,int> aux;
    pair <int, int> instalados[c];
    pair <int, int> disponiveis[n];
    for (i = 0; i < c; i++)
    {
        cin >> aux.first;
        cin >> aux.second;
        instalados[i] = aux;
    }

    for (i = 0; i < n; i++)
    {
        cin >> aux.first;
        cin >> aux.second;
        disponiveis[i] = aux;
    }
    cout << endl;
   
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < c; j++)
        {
            if(disponiveis[i].first == instalados[i].first)
                if(disponiveis[i].second > instalados[i].second)
                    cout << disponiveis[i].first << ' ' <<disponiveis[i].second;
            
        }
        
    }

}
    