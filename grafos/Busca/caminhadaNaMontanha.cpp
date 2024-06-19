#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100010;

vector<int> curtidas(NMAX); // Armazena o valor de curtidas de cada marco
unordered_map<int, vector<int>> adjacencia; // Lista de adjacência do grafo
vector<int> resposta(NMAX); // Armazena a resposta para cada marco
vector<bool> visitado(NMAX, false); // Marca se um nó já foi visitado
vector<int> lis; // Armazena a subsequência crescente

// Função DFS para explorar o grafo e calcular a subsequência crescente
void dfs(int no) {
    visitado[no] = true; // Marca o nó atual como visitado
    // Verifica se a curtida do nó atual é maior que o último elemento de lis
    if (curtidas[no] > lis.back()) {
        lis.push_back(curtidas[no]); // Adiciona a curtida do nó atual na lis
        resposta[no - 1] = lis.size(); // Atualiza a resposta com o tamanho da lis

        // Explora os filhos do nó atual
        for (auto& filho : adjacencia[no]) {
            if (!visitado[filho]) {
                dfs(filho); // Chama recursivamente a DFS para o filho
            }
        }

        lis.pop_back(); // Remove o elemento adicionado para restaurar o estado de lis
    } else {
        // Encontra a posição onde o elemento atual deveria estar na lis
        int idx = lower_bound(lis.begin(), lis.end(), curtidas[no]) - lis.begin();
        int valor = lis[idx]; // Guarda o valor atual na posição idx

        resposta[no - 1] = lis.size(); // Atualiza a resposta com o tamanho da lis
        lis[idx] = curtidas[no]; // Substitui o elemento na posição idx por curtidas[no]

        // Explora os filhos do nó atual
        for (auto& filho : adjacencia[no]) {
            if (!visitado[filho]) {
                dfs(filho); // Chama recursivamente a DFS para o filho
            }
        }

        lis[idx] = valor; // Restaura o valor original na posição idx
    }
}

// Função principal para resolver o problema
void resolver() {
    visitado[0] = true; // Marca o nó inicial como visitado
    lis.push_back(curtidas[0]); // Adiciona a curtida do nó inicial na lis

    // Chama a DFS para os filhos do nó inicial
    for (auto& filho : adjacencia[0]) {
        dfs(filho);
    }
}

int main() {
    int n;
    cin >> n; // Lê o número de marcos

    curtidas.resize(n); // Redimensiona o vetor de curtidas
    resposta.resize(n); // Redimensiona o vetor de respostas

    // Lê a estrutura do grafo
    for (int i = 1; i < n; i++) {
        int j;
        cin >> j;
        j--; // Ajusta o índice para ser zero-based
        adjacencia[i].push_back(j); // Adiciona a conexão i -> j
        adjacencia[j].push_back(i); // Adiciona a conexão j -> i
    }

    // Lê os valores de curtidas
    for (int i = 0; i < n; i++) {
        cin >> curtidas[i];
    }

    // Resolve o problema
    resolver();

    // Imprime a resposta
    cout << resposta[0];
    for (int i = 1; i < n - 1; i++) {
        cout << " " << resposta[i];
    }
    cout << endl;

    return 0;
}
