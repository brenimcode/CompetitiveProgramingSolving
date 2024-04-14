#include <bits/stdc++.h>

using namespace std;
#define NMAX 1010
#define par pair<int, int>

int n, m;
int mat[NMAX][NMAX];
int dcolum[4] = {0, 0, 1, -1};
int dlinha[4] = {1, -1, 0, 0};
int dist[NMAX][NMAX];
int cont;

void bfs(par p)
{
    queue<par> fila;
    fila.push(p);
    dist[p.first][p.second] = ++cont; // 1

    while (!fila.empty())
    {
        
        par atual = fila.front(); // pegamos o elemento da frente e retiramos.
        fila.pop();

        // agora vou iterar sobre os ADJ de atual.
        cont++;
        for (int i = 0; i < 4; i++)
        {
            int iV = atual.first + dcolum[i];
            int jV = atual.second + dlinha[i];
            //printf("-- (iV,jV) = (%d,%d) --\n",iV,jV);
            if (!(iV >= 0 && iV < n && jV >= 0 && jV < m))
                continue;
            if(mat[iV][jV] == 0) continue;
            par viz = par(iV, jV);
            //printf("---TESTE----\n");
            if (dist[viz.first][viz.second] == -1)
            {
                dist[viz.first][viz.second] = cont;
                fila.push(viz); // coloco ele na fila para processa-lo
            }
        }
    }
}

int main()
{
    int i, j;
    cin >> n >> m; // Leitura do número de tarefas e de relações de dependência
    queue <par> heap; 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]){
                heap.push(par(i,j));
            }
        }
    }

    memset(dist, -1, sizeof dist);
    cont = 0;
    int res = 0;
    while(!heap.empty()){
        par atual = heap.front();
        heap.pop();
        if(dist[atual.first][atual.second] == -1){
            res++;
            bfs(atual);            
        } 
        
    }

    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if(dist[i][j] == -1) res++;
        }
    }
    */
    cout <<  res << endl;

    return 0;
}
