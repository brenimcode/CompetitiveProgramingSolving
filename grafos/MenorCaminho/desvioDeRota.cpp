#include <bits/stdc++.h>

using namespace std;


#define DEBUG(x) cout << #x << " >>>> " << x << endl

// Definindo um tipo de dado para representar um par de inteiros (PESO, VERTICE)
typedef pair<int, int> Par;

// Definindo constantes para o número máximo de vértices e o valor de infinito
const int MAXN = 255;
const int INFINITO = 1e9 + 10;

// Variáveis globais para o número de vértices e arestas

int maior,menor;

bool visitado[MAXN];
vector<int> distancias(MAXN);

vector<Par> grafo[MAXN];
int N, M, C, K; // N = numero de cidades do PAIS, M = arestas, C = city na rota de serviços, K = Cidade que o veiculo foi consertado

// Função que implementa o algoritmo de Dijkstra
void dijkstra(int origem) {
    // Inicialização das distâncias: todas as distâncias começam como infinito
    for (int i = 0; i <= N; i++) {
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

   
    // 0,1...N-1 -- 0,1...C-1
    // origem = 0, Destino = C-1.

    while(cin >> N >> M >> C >> K){
        if(N == 0 && M == 0 && C == 0 && K ==0){
            break;
        }

       //bool ver = true;
        for (int i = 0; i < N; i++)
        {
           // if(i >= C) ver = false;
            visitado[i] = false;
        }
        
        
        // Lendo as arestas do grafo
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if((u >= C && v >= C) || (u<C && v<C && abs(u-v)==1)){
                grafo[u].push_back({w, v});
                grafo[v].push_back({w, u});
            }
            if(u>=C && v<C){
                grafo[u].push_back({w,v});
            }
            if(u<C && v>=C){
                grafo[v].push_back({w,u});
            }


            
        }
      
    // Executa o algoritmo de Dijkstra a partir do vértice de origem
        
        dijkstra(K);
        
        
        cout << distancias[C-1] << endl;
        

        // Limpar o grafo
        for (int i = 0; i < N; i++)
        {
            grafo[i].clear();
        }
        

    }



    return 0;
}
