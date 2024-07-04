
# Ciclo Euleriano em Grafo Direcionado

Imagine o seguinte problema: Dado um grafo direcionado \( G \) com \( N \) vértices e \( M \) arestas, diga se existe um Ciclo Euleriano em \( G \) e, caso exista, imprima a ordem dos vértices que você passa em algum Ciclo Euleriano.

A primeira vista, saber se existe um Ciclo Euleriano parece ser difícil, mas na verdade não é. Um Ciclo Euleriano existe em um grafo direcionado se, e somente se, essas duas condições forem verdadeiras:

1. Todos os vértices têm seu grau de entrada igual ao seu grau de saída, ou seja, todos os vértices têm a mesma quantidade de arestas entrando e saindo.
2. Ignorando os vértices isolados (com grau de entrada e saída sendo 0), o grafo é fracamente conexo. Ou seja, se transformarmos todas as arestas direcionadas em não-direcionadas, o grafo torna-se conexo.

É fácil ver que essas duas condições são necessárias e suficientes para a existência de um Ciclo Euleriano.

## Algoritmo para encontrar um Ciclo Euleriano

A estratégia para encontrar um Ciclo Euleriano é dividir o grafo em vários ciclos simples disjuntos e depois combiná-los para formar o Ciclo Euleriano. Isso pode ser feito com uma função recursiva `AcharCicloEuler(int u)`:

```cpp
vector<int> CicloEuleriano, edges_out[maxn];

void AcharCicloEuler(int u) {
    while (edges_out[u].size() != 0) {
        int v = edges_out[u].back(); // Pega uma aresta não utilizada
        edges_out[u].pop_back();     // Remove a aresta do grafo
        AcharCicloEuler(v);          // Tenta construir um Ciclo Euleriano a partir de v
    }
    CicloEuleriano.push_back(u);    // Adiciona u no caminho do Ciclo Euleriano
}
```

Após construir o caminho `CicloEuleriano`, é necessário inverter o vetor para obter a ordem correta dos vértices no Ciclo Euleriano.

## Ciclo Euleriano em Grafo Não-Direcionado

Em um grafo não-direcionado, as condições para existência de um Ciclo Euleriano são similares:

1. Todos os vértices têm grau par.
2. Ignorando os vértices isolados, o grafo é conexo.

A prova de que essas condições são necessárias e suficientes segue uma lógica semelhante ao caso do grafo direcionado.

Para encontrar um Ciclo Euleriano em um grafo não-direcionado, utiliza-se um algoritmo semelhante ao do grafo direcionado, com a diferença de que é necessário verificar se a aresta já foi utilizada ou não na direção inversa.

```cpp
// Implementação similar ao grafo direcionado, mas com ajustes para grafos não-direcionados
```

### Conclusão

Os algoritmos para encontrar Ciclos Eulerianos em grafos direcionados e não-direcionados são eficientes e baseados nas propriedades dos graus dos vértices e na conectividade do grafo. Eles permitem não apenas determinar a existência de um Ciclo Euleriano, mas também encontrar a ordem dos vértices que compõem esse ciclo.

Experimente testar manualmente esses algoritmos com diferentes exemplos de grafos para compreender melhor o seu funcionamento.
```

This Markdown file outlines the concepts and algorithms related to Eulerian Cycles in directed and undirected graphs.