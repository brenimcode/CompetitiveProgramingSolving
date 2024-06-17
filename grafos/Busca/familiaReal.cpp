#include <bits/stdc++.h>
using namespace std;

#define NMAX 10010

int n, m;
vector<int> grafo[NMAX];
int dist[NMAX];
bool compareceu[NMAX];

void bfs(int start) {
    queue<int> fila;
    dist[start] = 0;
    fila.push(start);

    while (!fila.empty()) {
        int vAtual = fila.front();
        fila.pop();

        for (int vViz : grafo[vAtual]) {
            if (dist[vViz] == -1) {
                dist[vViz] = dist[vAtual] + 1;
                fila.push(vViz);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int pai;
        cin >> pai;
        grafo[pai].push_back(i);
    }

    fill(dist, dist + n + 1, -1);
    fill(compareceu, compareceu + n + 1, false);

    for (int i = 0; i < m; i++) {
        int participante;
        cin >> participante;
        compareceu[participante] = true;
    }

    bfs(0);

    map<int, int> totalPorGeracao, compareceuPorGeracao;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1) {
            totalPorGeracao[dist[i]]++;
            if (compareceu[i]) {
                compareceuPorGeracao[dist[i]]++;
            }
        }
    }

    int maxGeracao = 0;
    for (auto geracao : totalPorGeracao) {
        maxGeracao = max(maxGeracao, geracao.first);
    }

    for (int i = 1; i <= maxGeracao; i++) {
        int total = totalPorGeracao[i];
        int presentes = compareceuPorGeracao[i];
        double proporcao = (total > 0) ? (double)presentes / total * 100 : 0.0;
        printf("%.2f ", proporcao);
    }
    cout << endl;

    return 0;
}
