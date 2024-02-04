#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,e,d,i;
    int ei,di;
    cin >> n >> e >> d;
    int pontuacoes[n];
    for ( i = 0; i < n; i++)
    {
        cin >> ei >> di;
        pontuacoes[i] = abs(ei-e) + abs(di-d);
    }
    int menor = pontuacoes[0];
    for (i = 0; i < n; i++)
    {
        if(menor > pontuacoes[i]){
            menor = pontuacoes[i];
        }
    }
    cout << menor;


    return 0;
}
