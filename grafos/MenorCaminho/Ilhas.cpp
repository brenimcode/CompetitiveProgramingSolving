#include <bits/stdc++.h>

using namespace std;

// Definindo um tipo de dado para representar um par de inteiros (PESO, VERTICE)
typedef pair<int, int> Par;

// Definindo constantes para o número máximo de vértices e o valor de infinito
const int MAXN = 1e5 + 10;
const int INFINITO = 1e9 + 10;

// Variáveis globais para o número de vértices e arestas
int N, M;
int maior,menor;

bool visitado[MAXN];
vector<int> distancias(MAXN);

vector<Par> grafo[MAXN];


// Função que implementa o algoritmo de Dijkstra
void dijkstra(int origem) {
    // Inicialização das distâncias: todas as distâncias começam como infinito
    for (int i = 1; i <= N+1; i++) {
        distancias[i] = INFINITO;
    }

    // A distância do vértice de origem para ele mesmo é 0
    distancias[origem] = 0;

    // Fila de prioridade para processar os vértices com as menores distâncias conhecidas primeiro
    priority_queue<Par, vector<Par>, greater<Par> > filaPrioridade;

    // Inserindo o vértice de origem na fila de prioridade com distância 0
    filaPrioridade.push({0, origem});

    // Enquanto a fila de prioridade não estiver vazia
    while (!filaPrioridade.empty()) {
        // Segunda etapa do algoritmo: selecionar o vértice com a menor distância
        int verticeAtual = filaPrioridade.top().second;
        filaPrioridade.pop();

        // Se o vértice já foi visitado, ignoramos e continuamos
        if (visitado[verticeAtual])
            continue;

        // Marcamos o vértice como visitado
        visitado[verticeAtual] = true;

        // Para cada vizinho do vértice atual
        for (auto vizinho : grafo[verticeAtual]) {
            int verticeVizinho = vizinho.second;
            int pesoAresta = vizinho.first;

            // Terceira etapa do algoritmo: relaxamento das arestas
            // Se encontrarmos um caminho mais curto para o vizinho, atualizamos sua distância
            if (distancias[verticeVizinho] > distancias[verticeAtual] + pesoAresta) {
                distancias[verticeVizinho] = distancias[verticeAtual] + pesoAresta;
                // Inserimos o vizinho na fila de prioridade com sua nova distância
                filaPrioridade.push({distancias[verticeVizinho], verticeVizinho});
            }
        }
        

    }
}

int main() {
    // Lendo o número de vértices e arestas
    cin >> N >> M;

    // Lendo as arestas do grafo
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        grafo[u].push_back({w, v});
        grafo[v].push_back({w, u});
    }
    int servidor;
    cin >> servidor;
    // Executa o algoritmo de Dijkstra a partir do vértice de origem
    
    dijkstra(servidor);

    sort(distancias.begin(), distancias.begin()+N+1);
    maior = distancias[N], menor = distancias[2];


    cout << maior - menor << endl;

    return 0;
}
