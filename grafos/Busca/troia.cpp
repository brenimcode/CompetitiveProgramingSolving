#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 100100

int n,m;
int componente[NMAX];
vector<int> vizinhos[NMAX]; // Vizinhos dos vertices, [1,2,3...M]

void bfs(int v)
{
    queue<int> fila;
    componente[v] = 1;
    fila.push(v);
    while(!fila.empty()){

        int verticeAtual = fila.front();
        fila.pop();


        for (int i = 0; i < (int) vizinhos[verticeAtual].size() ; i++)
        {
            int vizinho = vizinhos[verticeAtual][i];
            if(componente[vizinho] == -1){
                componente[vizinho] = 1;
                fila.push(vizinho);
            }
        }
    }

}

int main()
{

    cin >> n >> m;

    while(m--){
        int a,b;
        cin >> a >> b;
        vizinhos[a].push_back(b); // A se liga com B, A -> B
        vizinhos[b].push_back(a); // B se liga com A, B -> A
    }

    for (int i = 1; i <= n; i++)
    {
        
        componente[i] = -1;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(componente[i] == -1){
            sum++;
            bfs(i);
        }
    }

    cout << sum << endl;

    return 0;
}