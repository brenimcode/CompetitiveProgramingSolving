#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define NMAX 100045
#define INF LLONG_MAX

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii; // {num_cidades_dividas, distancia_total, cidade_atual}

vector<pii> adj[NMAX]; // lista de adjacência {vizinho, peso}
unordered_set<int> cidades_dividas; // conjunto de cidades onde Lex deve dinheiro

// Armazenar distâncias e número de cidades com dívidas
int dist[NMAX][2]; // dist[i][0] - número de cidades com DIVIDAS para alcançar a cidade i
                   // dist[i][1] - DISTANCIA mínima para alcançar a cidade i com o número de cidades com dívidas em dist[i][0]

// Função que implementa o algoritmo de Dijkstra modificado
void dijkstra(int inicio, int n) {
    // Inicializa o vetor de distâncias com valores máximos
    for (int i = 0; i <= n; ++i) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    // Inicializa a cidade de início
    dist[inicio][0] = cidades_dividas.count(inicio); // Conta a dívida da cidade inicial se houver
    dist[inicio][1] = 0;
    pq.push({dist[inicio][0], 0, inicio}); // Inicializa a fila de prioridade

    while (!pq.empty()) {
        // Pega o elemento com a menor prioridade (menor número de cidades com dívidas e, em caso de empate, menor distância)
        auto [num_cidades_dividas, distancia_total, u] = pq.top();
        pq.pop();

        // Verifica se o caminho atual é pior do que o já encontrado
        if (num_cidades_dividas > dist[u][0] || (num_cidades_dividas == dist[u][0] && distancia_total > dist[u][1])) {
            continue;
        }

        // Explora os vizinhos da cidade atual
        for (auto &[v, w] : adj[u]) {
            // Novo número de cidades com dívidas = dívidas predecessor + dívida atual se houver
            int novo_cidades_dividas = num_cidades_dividas + cidades_dividas.count(v); 
            // Nova distância total = distância predecessor + peso atual
            int nova_distancia_total = distancia_total + w;

            // Atualiza a distância e o número de cidades com dívidas se encontrarmos um caminho melhor
            if (novo_cidades_dividas < dist[v][0] || 
                (novo_cidades_dividas == dist[v][0] && nova_distancia_total < dist[v][1])) {
                dist[v][0] = novo_cidades_dividas;
                dist[v][1] = nova_distancia_total;
                pq.push({novo_cidades_dividas, nova_distancia_total, v});
            }
        }
    }

    // Imprime o resultado: número mínimo de cidades com dívidas e a menor distância para chegar à cidade 'n'
    cout << dist[n][0] << " " << dist[n][1] << endl;
}

int32_t main() {
    _
    int n, m, d;
    cin >> n >> m >> d;

    int a, b;

    // Lê as cidades onde Lex deve dinheiro
    for (int i = 0; i < d; i++) {
        cin >> a;
        cidades_dividas.insert(a);
    }

    // Lê as estradas entre as cidades
    for (int i = 0; i < m; i++) {
        cin >> a >> b; // adicionando os pares
        adj[a].push_back({b, 1}); // vertice e peso
        adj[b].push_back({a, 1});
    }

    // Chama a função dijkstra a partir da cidade 1
    dijkstra(1, n);

    return 0;
}
