#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005]; // Vetor de adjacências para representar as relações de dependência
int grauEntrada[100005]; // Vetor para contar o grau de entrada de cada tarefa
vector<int> ordem; // Vetor para armazenar a ordem ótima de execução das tarefas

bool topologicalSort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq; // Fila de prioridade para armazenar tarefas de maior prioridade

    // Inicializa a fila de prioridade com as tarefas de grau de entrada zero
    for (int i = 0; i < n; i++) {
        if (grauEntrada[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top(); // Tarefa de maior prioridade
        pq.pop();
        ordem.push_back(u); // Adiciona a tarefa na ordem de execução

        // Atualiza o grau de entrada das tarefas adjacentes
        for (int v : adj[u]) {
            grauEntrada[v]--;
            if (grauEntrada[v] == 0) {
                pq.push(v); // Se o grau de entrada de uma tarefa se torna zero, adiciona à fila de prioridade
            }
        }
    }

    // Verifica se todas as tarefas foram incluídas na ordem
    return (ordem.size() == n);
}

int main() {
    int n, m;
    cin >> n >> m; // Leitura do número de tarefas e de relações de dependência

    // Leitura das relações de dependência e construção do grafo
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        grauEntrada[b]++;
    }

    // Executa a ordenação topológica
    if (topologicalSort(n)) {
        // Imprime a ordem de execução das tarefas
        for (int i = 0; i < n; i++) {
            cout << ordem[i] << endl;
        }
    } else {
        cout << "*" << endl; // Caso não seja possível ordenar as tarefas
    }

    return 0;
}
