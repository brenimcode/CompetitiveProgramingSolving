#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par pair<int, int> // (custo,vertice)
#define MAXN 200005

int n, m, q;                  // vertice,arestas
vector<pair<int, par>> edges; // Lista de arestas (custo, (vértice1, vértice2))
int parent[MAXN];             // Vetor de pais para Union-Find
int tamanho[MAXN];            // Vetor de tamanhos para Union-Find

// Função para inicializar Union-Find
void init(int n)
{
    for (int i = 0; i <= n; ++i)
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

void inicializa()
{

    init(n + 2);                      // inicializo union find
    sort(edges.begin(), edges.end()); // sort no vetor
    // Deixo toda union find pré pronta
    for (auto e : edges)
    {
        int u = e.second.first;
        int v = e.second.second;

        if (find(u) != find(v))
        {
            unite(u, v);
        }
    }
}

bool kruskal(int w, int v1, int v2)
{

    vector<pair<int, par>> edges_2 = edges; // faço copia

    // Inicializo a union find de cada um dos novos vertices.
    parent[v1] = v1;
    tamanho[v1] = 1;
    parent[v2] = v2;
    tamanho[v2] = 1;

    edges_2.push_back({w, {v1, v2}});
    edges_2.push_back({w, {v2, v1}});

    set<pair<int, par>> mst; // onde vou criar mst

    sort(edges_2.begin(), edges_2.end()); // sort

    for (auto e : edges_2)
    {
        int custo = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (find(u) != find(v))
        {
            unite(u, v);
            mst.insert({custo, {u, v}});
        }
    }

    if (mst.find({w, {v1, v2}}) != mst.end() || mst.find({w, {v2, v1}}) != mst.end())
    {
        parent[v1] = v1;
        tamanho[v1] = 1;
        parent[v2] = v2;
        tamanho[v2] = 1;
        return true;
    }
    parent[v1] = v1;
    tamanho[v1] = 1;
    parent[v2] = v2;
    tamanho[v2] = 1;
    return false;
}

int32_t main()
{
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
        edges.push_back({c, {b, a}});
    }
    inicializa();

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // adiciono uma aresta e faço a seguinte pergunta: Ei está em Ti?

        if (kruskal(c, a, b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}