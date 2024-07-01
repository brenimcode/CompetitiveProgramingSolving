/*
 Convex HULL - Camadas de Cebola SBC 2016 - neps/1610
Graham Scan algorithm
*/

#include <bits/stdc++.h>
#define ponto pair<int, int>
#define x first
#define y second
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

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
    return (valor > 0) ? 1 : 2; // horário ou anti-horário
}

// Função para calcular a distância ao quadrado entre dois pontos
int distQuadrada(ponto p1, ponto p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Função de comparação para ordenar os pontos por ângulo polar e distância
bool comparar(ponto p1, ponto p2)
{
    int o = orientacao(pontoInicial, p1, p2);
    if (o == 0)
        return distQuadrada(pontoInicial, p2) >= distQuadrada(pontoInicial, p1) ? false : true;
    return (o == 2);
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

    // Encontrar o ponto com a menor coordenada y (e menor x em caso de empate)
    int menorY = pontos[0].y, indiceMenorY = 0;
    for (int i = 1; i < n; i++)
    {
        int y = pontos[i].y;
        if ((y < menorY) || (y == menorY && pontos[i].x < pontos[indiceMenorY].x))
        {
            menorY = pontos[i].y;
            indiceMenorY = i;
        }
    }

    // Colocar o ponto com a menor coordenada y na primeira posição
    swap(pontos[0], pontos[indiceMenorY]);
    pontoInicial = pontos[0];

    // Ordenar os pontos por ângulo polar em relação ao ponto inicial
    sort(pontos.begin() + 1, pontos.end(), comparar);

    // Usar uma pilha para construir o fecho convexo
    stack<ponto> pilha;

    // Processar os pontos
    for (int i = 0; i < n; i++)
    {

        // Remover pontos que não formam uma orientação anti-horária
        // Enquanto a pilha tiver pelo menos 2 elementos
        while (pilha.size() > 1 && orientacao(proximoTopo(pilha), pilha.top(), pontos[i]) != 2)
            pilha.pop();
        pilha.push(pontos[i]); // adiciona o ponto na pilha e repete.
    }

    // impressao do resultado a cebola deve ser levada SIM, ou NAO
    cout << pilha.size() << endl;
    while (!pilha.empty())
    {
        ponto aux = pilha.top();
        pilha.pop();
        cout << aux.x << ' ' << aux.y << endl;
    }
}

int32_t main()
{
    int n;

    while (cin >> n)
    {
       // pontos.assign(n,0);
        while (n--)
        {
            int x, h;
            cin >> x >> h;
            pontos.push_back({x, h});
        }
        fechoConvexo();
        pontos.clear();
    }

    return 0;
}