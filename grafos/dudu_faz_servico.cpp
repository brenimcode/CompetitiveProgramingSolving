#include <bits/stdc++.h>
using namespace std;

#define NMAX 30100

vector<int> grafo[NMAX];
int visitados[NMAX];
int cont;
vector<bool> pilha_de_recursao;

bool dfsR(int vertice) {
    visitados[vertice] = cont++;
    pilha_de_recursao[vertice] = true; // adiciona o vértice na pilha

    for (int adjacente : grafo[vertice]) {
        if (visitados[adjacente] == -1) {
            if (dfsR(adjacente)) {
                return true;
            }
        } else if (pilha_de_recursao[adjacente]) {
            return true;
        }
    }
    pilha_de_recursao[vertice] = false; // remove o vértice da pilha
    return false;
}

bool GrafoDSR(int n) {
    cont = 0; // Para assinar em qual momento o vertice foi visitado.
    pilha_de_recursao.assign(n + 1, false); // Inicializa a pilha de recursao com false
    memset(visitados, -1, sizeof(visitados));

    for (int i = 1; i <= n; i++) {
        if (visitados[i] == -1) {
            if (dfsR(i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t, n, m, a, b; // t é qtd de casos de teste,arestas A e B
    cin >> t;
    for (int conta = 0; conta < t; conta++) {
        cin >> n >> m; // M é |arestas| e N é |vertices|
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            grafo[a].push_back(b);
        }
        if (GrafoDSR(n))
            printf("SIM\n");
        else
            printf("NAO\n");

        // Limpa o grafo para o próximo caso de teste
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
        }
    }
    return 0;
}
