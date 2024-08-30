## Dado um grafo G, achar sua árvore geradora mínima.


Para resolver este problema, você pode utilizar algoritmos clássicos de **Árvore Geradora Mínima (Minimum Spanning Tree - MST)**, já que o objetivo é conectar todas as cidades (nós) com o menor custo total possível, utilizando um subconjunto das rodovias (arestas). As principais abordagens para resolver esse problema são:

### 1. **Algoritmo de Kruskal**
   - **Estrutura**: Esse algoritmo utiliza a estrutura de **conjuntos disjuntos** (Union-Find ou Disjoint Set Union - DSU) para gerenciar e verificar ciclos enquanto constrói a árvore geradora mínima.
   - **Passos**:
     1. Ordene todas as arestas pelo seu peso (comprimento da rodovia).
     2. Itere pelas arestas, adicionando a menor aresta ao conjunto da árvore, desde que ela não forme um ciclo.
     3. Continue até que todas as cidades estejam conectadas.

### 2. **Algoritmo de Prim**
   - **Estrutura**: Utiliza uma **fila de prioridade (Priority Queue)** ou uma estrutura similar para selecionar a próxima aresta de menor peso.
   - **Passos**:
     1. Comece em qualquer cidade.
     2. Marque-a como visitada e adicione todas as arestas que saem dessa cidade na fila de prioridade.
     3. Extraia a aresta de menor peso da fila, conecte a próxima cidade e repita o processo até que todas as cidades estejam conectadas.

### Quando usar:
- **Kruskal**: Geralmente é mais eficiente em grafos com muitas arestas (denso) e se as arestas já estão previamente ordenadas ou podem ser facilmente ordenadas.
- **Prim**: Pode ser mais eficiente em grafos esparsos (poucas arestas) e funciona bem com uma matriz de adjacência.

### Complexidade:
- **Kruskal**: O(E log E), onde E é o número de arestas, devido à ordenação das arestas.
- **Prim**: O(E log V), onde V é o número de vértices e E o número de arestas, dependendo da implementação da fila de prioridade.

Ambos os algoritmos garantem a construção de uma árvore geradora mínima, que é o subconjunto de arestas com a menor soma de pesos possível, conectando todas as cidades. 

### Resumo:
- **Kruskal**: Bom para grafos densos; precisa ordenar arestas.
- **Prim**: Eficiente em grafos esparsos; começa a partir de um nó específico.
