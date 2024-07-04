/*
Duende perdido - Obi 2005
Author: Brenimcode

Celulas:
    3 = posicao do duende
    2 = bloqueio
    1 = Caminho valido
    0  = Saida

    Caminho minimo, BFS or DIJKSTRA


*/

#include <bits/stdc++.h>

using namespace std;
#define NMAX 12
#define par pair<int,int> // (x,y)
#define DEBUG(x) cout << #x << " >>>> " << x << endl
// 3 é a posição do duende

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

int n, m, xi, yi;
int adj[NMAX][NMAX];
int dist[NMAX][NMAX];

string mostrarSeta(int k) {
    switch (k) {
        case 0: return "direita";
        case 1: return "esquerda";
        case 2: return "baixo";
        case 3: return "cima";
        default: return "";
    }
}

int bfs(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = -1;
        }
    }

    dist[x][y] = 0;
    queue<par> fila;

    fila.push({x,y});

    while (!fila.empty())
    {
        // pegando o elemento mais a frente na fila
        par atual = fila.front();
        fila.pop();
        int iAtual = atual.first;
        int jAtual = atual.second;
        
        for (int k = 0; k < 4; k++)
        {
            int iViz = iAtual + drow[k];
            int jViz = jAtual + dcol[k];
            
            if(iViz < 1 || iViz > n || jViz < 1 || jViz > m) continue;

            if(adj[iViz][jViz] == 0){
                // Cheguei na saida
                return dist[iAtual][jAtual] + 1;
            }

            if(dist[iViz][jViz] == -1 && adj[iViz][jViz] == 1){
                dist[iViz][jViz] = dist[iAtual][jAtual] + 1;
                fila.push({iViz,jViz});
            }
        }
    }

    return -1;
}

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
            if(adj[i][j] == 3){
                xi = i;
                yi = j;
            }
        }
    }

    cout << bfs(xi,yi) << endl;
}