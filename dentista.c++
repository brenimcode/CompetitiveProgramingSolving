#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,i,a,b;
    cin >> n;
    pair <int,int> consultas[n];
    int quantidade = 1;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        consultas[i] = {a,b};
    }
    for (i = 0; i < n; i++)
    {
        
        if(consultas[i].second <= consultas[i+1].first){
            //da pra fazer essa parada.
            quantidade++;
        } 
    }
    cout << quantidade;

    return 0;
}