#include <bits/stdc++.h>
#define ponto pair<int, int>
#define x first
#define y second
#define int long long
using namespace std;


ponto pontoInicial;   // Ponto inicial de referência
vector<ponto> pontos; // Vetor global para armazenar os pontos

// Função para determinar a orientação dos pontos (p, q, r)
// Retorna 0 se colinear, 1 se horário, 2 se anti-horário
int orientacao(ponto p, ponto q, ponto r)
{
    int valor = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (valor == 0)
        return 0;               // colinear
    return (valor > 0) ? 1 : -1; // horário ou anti-horário
}

// Função para calcular a distância ao quadrado entre dois pontos
int distQuadrada(ponto p1, ponto p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Função de comparação para ordenar os pontos por ângulo polar e distância
bool comparar(ponto p1, ponto p2)
{
    return p1.x < p2.x;
}

// Função para obter o segundo elemento do topo da pilha
ponto proximoTopo(stack<ponto> &pilha)
{
    ponto aux = pilha.top();
    pilha.pop();
    ponto ans = pilha.top();
    pilha.push(aux);
    return ans;
}

// Função para encontrar o fecho convexo usando o algoritmo de Graham Scan
void fechoConvexo()
{
    int n = (int)pontos.size();

    // Ordenar os pontos por coordenada x
    sort(pontos.begin(), pontos.end(), comparar);

    // Usar uma pilha para construir o fecho convexo
    stack<ponto> pilha;

    // Processar os pontos restantes
    for (int i = 0; i < n; i++)
    {
        // Remover pontos que não formam uma orientação anti-horária
        // Enquanto a pilha tiver pelo menos 2 elementos, E a orientacao de 2º da Pilha, 1º pilha (AB), e a (BC)
        // tiverem orientação anti-horária TIRA da pilha

        while (pilha.size() > 1 && orientacao(proximoTopo(pilha), pilha.top(), pontos[i]) <= 0)
            pilha.pop();
        pilha.push(pontos[i]); // adiciona o ponto na pilha e repete.
    }

    // impressao
    cout << pilha.size()-1 << endl;
    
}




int32_t main()
{
    int n;
    cin >> n;
    while(n--){
        int x,h;
        cin >> x >> h;
        pontos.push_back({x,h});
    }

    fechoConvexo();

    return 0;
}
