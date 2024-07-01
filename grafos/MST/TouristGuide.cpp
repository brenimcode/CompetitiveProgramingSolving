#include <bits/stdc++.h>
using namespace std;

#define int long long
#define par pair<int, int> // (custo,vertice)
#define MAXN 200005

int n, m;                     // vertice,arestas
int s,d,t; // start, destiny, number of tourists to be guided
vector<pair<int, par>> edges; // Lista de arestas (custo, (vértice1, vértice2))
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

// funcao para decrescente
bool compara(pair<int, par> e1, pair<int, par> e2){
    return e1.first > e2.first;
}

// Função principal para o algoritmo de Kruskal
int Kruskal()
{
   // int custoTotal = 0, trips = 0;
    swap(edges[s], edges[1]);
    // colocando o elemento s° em 1º posição

    sort(edges.begin()+2, edges.end(), compara); //Ordeno agora de forma crescente pois: Maximum Spanning Tree
    init(n);               // inicializo Union FIND
    for (const auto &edge : edges)
    {
        int custo = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        // vejo se eles estao na mesma componente
        if (find(u) != find(v))
        {
            unite(u, v);
            
             // Verificar se s e d estão conectados na mesma componente
            if (find(s) == find(d))
            {
                // Calcular o número mínimo de viagens
                return (t + custo - 1) / custo; // t dividido pelo peso da aresta mais pesada (arredondado para cima)
            }
        }
    }

    return -1;
}

int32_t main()
{

    int scenario = 1;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        edges.clear(); // limpando o vector
        edges.push_back({0,{0,0}}); // primeira posição não é usada
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
            edges.push_back({c, {b, a}});
        }
        cin >> s >> d >> t;
        int ans = Kruskal();
        cout << "Scenario #" << scenario++ << endl;
        cout << "Minimum Number of Trips = " << ans << endl << endl;
    }
}