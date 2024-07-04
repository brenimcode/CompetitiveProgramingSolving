#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> CicloEuleriano, adj[MAXN];
int degree[MAXN];
bool visited[MAXN];
unordered_set<int> vertices; 


// Função para encontrar um Ciclo Euleriano em um grafo não direcionado
void AcharCicloEuler(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();  // Escolhe uma aresta de u
        adj[u].pop_back();      // Remove a aresta do grafo
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (*it == u) {     // Remove a aresta de volta para u
                adj[v].erase(it);
                break;
            }
        }
        AcharCicloEuler(v);    // Continua buscando a partir de v
    }
    CicloEuleriano.push_back(u); // Adiciona u ao ciclo euleriano encontrado
}

// Função para verificar se um grafo possui um Ciclo Euleriano
/*
bool VerificarCicloEuleriano(int N) {
    // Verifica se todos os vértices têm grau par
    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }

    // Verifica se o grafo é conexo usando uma busca em profundidade (DFS)
    stack<int> Stack;
    Stack.push(1);      // Começa a DFS a partir do vértice 1
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    int num_visited = 1;

    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                Stack.push(v);
                num_visited++;
            }
        }
    }

    return (num_visited == N); // Retorna verdadeiro se todos os vértices foram visitados
}
*/

void dfs(int v){
    visited[v] = true;

    for(auto viz : adj[v]){
        if(!visited[viz]){
            dfs(viz);
        }
    }
}

bool VerificarCicloEuleriano(int N) {
    // Verifica se todos os vértices têm grau PAR
    for (int i = 1; i <= N; ++i) {
        if (degree[i]%2 != 0) {
            return false;
        }
    }

    for (int i = 1; i <= N; ++i) { // Inicializa visited como false.
        visited[i] = false;
    }

    for (int i = 1; i <= N; ++i) { // vejo se o grafo é conexo.
        if (!visited[i]) {
            dfs(i);
        }
    }

    for(auto vt : vertices){ // verifico se todos vertices que NAO TEM GRAU 0 foram visitados
        if (!visited[vt]) {
            return false;
        }
    }

    return true;
}


int main() {
    // Exemplo de configuração do grafo
    int N, M;
    cin >> N >> M;

//Inicializando degree
for (int i = 0; i <= N; i++)
{
    degree[i] = 0;
}

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vertices.insert(u);
        vertices.insert(v);
        degree[u]++;
        degree[v]++;
    }

    // Verifica se o grafo possui um ciclo euleriano
    if (!VerificarCicloEuleriano(N)) {
        cout << "IMPOSSIBLE\n";
    } else {
        // Encontra um ciclo euleriano iniciando em qualquer vértice (supondo vértice 1)
        AcharCicloEuler(1);

        // Inverte o vetor para obter a ordem correta dos vértices no ciclo euleriano
        reverse(CicloEuleriano.begin(), CicloEuleriano.end());

        // Imprime o ciclo euleriano
        for (int v : CicloEuleriano) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
