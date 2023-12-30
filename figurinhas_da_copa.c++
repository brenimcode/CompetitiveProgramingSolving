#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,c,m,i,j,cont=0;
    cin >> n >> c >> m;

    int vet1[n],vet2[m];
    for (i = 0; i < c; i++)
    {
            cin >> vet1[i];   
    }
    for (i = 0; i < m; i++)
    {
            cin >> vet2[i];   
    }

    for (i = 0; i < c; i++)
    {
            for (j = 0; j < m; j++)
            {
                if(vet1[i] == vet2[j]){
                    cont++;
                    break;
                }
            }
            
    }

    cout << c-cont;
    
}   