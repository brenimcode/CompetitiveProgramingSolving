#include <bits/stdc++.h>
using namespace std;

#define NMAX 10010

int n, m, l, p;
vector<int> grafo[NMAX];
int dist[NMAX];

void bfs(int start)
{

    for (int i = 0; i <= n; i++)
    {
        dist[i] = -1;
    }

    queue<int> fila;
    dist[start] = 0;
    fila.push(start);

    set<int> result;

    while (!fila.empty())
    {
        int vAtual = fila.front();
        fila.pop();

        for (int vViz : grafo[vAtual])
        {
            if (dist[vViz] == -1)
            {
                dist[vViz] = dist[vAtual] + 1;
                if (dist[vViz] <= p)
                {
                    result.insert(vViz);
                }
                fila.push(vViz);
            }
        }
    }

    for (auto it : result)
    {
        cout << it << " ";
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    int i, j;
    int mat[n][m];
    int maiorLinha = 0;
    for (i = 0; i < n; i++)
    {
        int current = 0;
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            current+=mat[i][j];
        }
        if(maiorLinha < current){
            maiorLinha = current;
        }
    }
    int maiorColuna = 0;
    for (i = 0; i < m; i++)
    {
        int current = 0;
        for (j = 0; j < n; j++)
        {
            current+=mat[j][i];
        }
        if(maiorColuna < current){
            maiorColuna = current;
        }
    }

    if(maiorLinha > maiorColuna){
        cout << maiorLinha << endl;
    }else{
        cout << maiorColuna << endl;
    }

    return 0;
}
