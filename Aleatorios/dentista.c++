#include <bits/stdc++.h>

using namespace std;

pair <int,int> consultas[10100];

bool ordenar(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main()
{
    int n,i,ini,fim,livre=0;
    cin >> n;
    
    int quantidade = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> ini >> fim;
        consultas[i] = {ini,fim};
    }
    sort(consultas+1,consultas+n+1,ordenar);

    for (i = 1; i <= n; i++)
    {
        
        if(consultas[i].first >= livre ){
            quantidade++;
            livre = consultas[i].second;
        } 
    }
    cout << quantidade;

    return 0;
}