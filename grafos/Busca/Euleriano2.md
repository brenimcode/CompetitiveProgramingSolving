
# Ciclo Euleriano em Grafo Direcionado

## Introdução

Imagine o seguinte problema: Dado um grafo direcionado \( G \) com \( N \) vértices e \( M \) arestas, diga se existe um Ciclo Euleriano em \( G \) e, caso exista, imprima a ordem dos vértices que você passa em algum Ciclo Euleriano.

### Condições para Existência de Ciclo Euleriano

Um Ciclo Euleriano em um grafo direcionado existe se e somente se:

1. Todos os vértices têm seu grau de entrada igual ao seu grau de saída.
2. Ignorando os vértices isolados (com grau de entrada e saída sendo 0), o grafo é fracamente conexo.

Essas condições são não apenas necessárias, mas também suficientes para a existência de um Ciclo Euleriano.

## Estratégia para Encontrar um Ciclo Euleriano

Para encontrar um Ciclo Euleriano em um grafo direcionado que atenda às condições acima, podemos seguir uma estratégia baseada em dividir o grafo em ciclos simples disjuntos e depois combiná-los.

### Passos para Encontrar o Ciclo Euleriano

1. **Verificação de Condições**: Verificar se todos os vértices têm grau de entrada igual ao grau de saída.
2. **Divisão em Ciclos Simples**:
   - Implementar uma função recursiva `AcharCicloEuler(u)` que, dado um vértice \( u \):
     - Enquanto houver arestas não utilizadas saindo de \( u \):
       - Escolher uma aresta não utilizada que sai de \( u \) para um vértice \( v \).
       - Marcar essa aresta como utilizada.
       - Chamar recursivamente `AcharCicloEuler(v)`.
     - Adicionar \( u \) à resposta (no caminho).
   - Inverter o vetor que guarda o caminho para obter a ordem correta dos vértices.

### Exemplo de Implementação

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100005;
vector<int> CicloEuleriano, edges_out[maxn];

void AcharCicloEuler(int u) {
    while (!edges_out[u].empty()) {
        // Escolhe uma aresta de u que não foi usada
        int v = edges_out[u].back();
        edges_out[u].pop_back(); // Marca a aresta como utilizada

        // Chama recursivamente para construir um ciclo euleriano começando de v
        AcharCicloEuler(v);
    }
    // Adiciona u à resposta
    CicloEuleriano.push_back(u);
}

int main() {
    // Exemplo de configuração do grafo
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges_out[u].push_back(v);
    }

    // Encontra um ciclo euleriano iniciando em qualquer vértice
    AcharCicloEuler(1); // Supondo que queremos começar do vértice 1

    // Inverte o vetor para obter a ordem correta dos vértices no ciclo euleriano
    reverse(CicloEuleriano.begin(), CicloEuleriano.end());

    // Imprime o ciclo euleriano
    cout << "Ordem dos vértices no Ciclo Euleriano:\n";
    for (int v : CicloEuleriano) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
```

Este código exemplifica como encontrar e imprimir a ordem dos vértices em um Ciclo Euleriano em um grafo direcionado. Certifique-se de adaptar o exemplo às suas necessidades específicas, especialmente em relação à entrada do grafo e à escolha do vértice inicial para começar a busca do ciclo euleriano.

Este arquivo está pronto para ser usado como referência para entender e implementar o algoritmo de Ciclo Euleriano em grafos direcionados de maneira clara e didática.