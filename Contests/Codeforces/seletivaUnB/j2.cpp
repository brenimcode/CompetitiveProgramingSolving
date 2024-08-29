#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Aresta {
    int destino;
    long long peso;
};

void dijkstra(int inicio, vector<vector<Aresta>>& grafo, vector<long long>& distancia) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, inicio});
    distancia[inicio] = 0;

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > distancia[u])
            continue;

        for (auto& vizinho : grafo[u]) {
            int v = vizinho.destino;
            long long peso_uv = vizinho.peso;
            if (distancia[u] + peso_uv < distancia[v]) {
                distancia[v] = distancia[u] + peso_uv;
                pq.push({distancia[v], v});
            }
        }
    }
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, M;
        cin >> N >> M;
        
        vector<vector<Aresta>> grafo(N + 1);
        vector<vector<Aresta>> grafoReverso(N + 1);
        
        for (int i = 0; i < M; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            grafo[u].push_back({v, w});
            grafo[v].push_back({u, w});
            grafoReverso[v].push_back({u, w});
            grafoReverso[u].push_back({v, w});
        }
        
        vector<long long> d1(N + 1, INF);
        vector<long long> d2(N + 1, INF);
        
        dijkstra(1, grafo, d1); // Menor caminho de Brasília (cidade 1) para todas as outras no grafo original
        dijkstra(N, grafoReverso, d2); // Menor caminho de Fortaleza (cidade N) para todas as outras no grafo reverso
        
        // Encontrar a menor soma de d1[v] + d2[v]
        long long menorTempoTotal = INF;
        vector<int> rotaIda, rotaVolta;
        int a = -1, b = -1;

        for (int v = 2; v <= N - 1; ++v) {
            if (d1[v] < INF && d2[v] < INF) {
                long long tempoTotal = d1[v] + d2[v];
                if (tempoTotal < menorTempoTotal) {
                    menorTempoTotal = tempoTotal;
                    a = v;
                    b = v;
                }
            }
        }
        
        if (menorTempoTotal == INF) {
            cout << -1 << "\n";
        } else {
            rotaIda.push_back(1); // Brasília
            rotaIda.push_back(a);
            rotaIda.push_back(N); // Fortaleza
            
            rotaVolta.push_back(N); // Fortaleza
            rotaVolta.push_back(b);
            rotaVolta.push_back(1); // Brasília
            
            cout << menorTempoTotal << " " << rotaIda.size() << " " << rotaVolta.size() << "\n";
            for (int cidade : rotaIda) {
                cout << cidade << " "; 
            }
            cout << "\n";
            for (int cidade : rotaVolta) {
                cout << cidade << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
