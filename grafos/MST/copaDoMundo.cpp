#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par pair<int, int> // (custo,vertice)
#define MAXN 200

struct t_edge{
    int custo,u,v;
    bool rodovia; // é rodovia?
};

int n, f, r;                     // vertice,arestas
vector<t_edge> edges; // Lista de arestas (custo, (vértice1, vértice2))

int parent[MAXN];             // Vetor de pais para Union-Find
int tamanho[MAXN];            // Vetor de tamanhos para Union-Find

// Função para inicializar Union-Find
void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        tamanho[i] = 1; // Inicialmente, cada conjunto tem tamanho 1
    }
}

// Função para encontrar o representante (raiz) de um conjunto usando compressão de caminho
int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]); // Compressão de caminho
    }
    return parent[u];
}

// Função para unir dois conjuntos usando Union by Size
void unite(int u, int v)
{
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v)
    {
        if (tamanho[root_u] > tamanho[root_v])
        {
            parent[root_v] = root_u;
            tamanho[root_u] += tamanho[root_v];
        }
        else
        {
            parent[root_u] = root_v;
            tamanho[root_v] += tamanho[root_u];
        }
    }
}

bool compara(t_edge a, t_edge b){
    if(a.rodovia != b.rodovia){
        return a.rodovia < b.rodovia;
    }
    return a.custo < b.custo;
}

// Função principal para o algoritmo de Kruskal
void Kruskal()
{
    int custoTotal = 0;
    sort(edges.begin(), edges.end(), compara); // ordenando as arestas
    init(n);                          // inicializo Union FIND

    for (const auto &edge : edges)
    {
        int custo = edge.custo;
        int u = edge.u;
        int v = edge.v;
        // vejo se eles estao na mesam componente
        if (find(u) != find(v))
        {
            unite(u, v);
            custoTotal += custo;
        }
    }

    cout << custoTotal << endl;
}

int32_t main()
{
    cin >> n >> f >> r;
    int a, b, c;
    for (int i = 0; i < f; i++) // ferrovias
    {
        cin >> a >> b >> c;
        t_edge aux;
        aux.custo = c;
        aux.rodovia = false;
        aux.u = a;
        aux.v = b;
        edges.push_back(aux);
    }

    for (int i = 0; i < r; i++) // rodovias
    {
        cin >> a >> b >> c;
        t_edge aux;
        aux.custo = c;
        aux.rodovia = true;
        aux.u = a;
        aux.v = b;
        edges.push_back(aux);
    }


    Kruskal();
}