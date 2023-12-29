#include <bits/stdc++.h>

using namespace std;

bool marcados[100000];

vector <int> grafo[100000];

void dfs(int x){
    for(auto viz:grafo[x]){
        if(marcados[viz] == 0){
            //nao foi marcado ainda
            marcados[viz] = 1;
            dfs(viz);
        }
    }
}


int main()
{
    int n, i, j,a,b;
    cin >> n;
    // as peças sao de 1 a N

    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
        //A está pendurada em B

    }
    

    return 0;
}