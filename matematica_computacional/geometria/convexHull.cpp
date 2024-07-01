#include <bits/stdc++.h>
#define ponto pair<int, int>
#define x first
#define y second
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

    // Verificar se todos os pontos estão na mesma coordenada
    bool mesmaCoordenada = true;
    for (int i = 1; i < n; i++)
    {
        if (pontos[i] != pontos[0])
        {
            mesmaCoordenada = false;
            break;
        }
    }

    if (mesmaCoordenada)
    {
        // Imprimir os pontos se todos estiverem na mesma coordenada
        cout << 1 << endl;

        cout << pontos[0].x << ' ' << pontos[0].y << endl;

        return;
    }

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

    // Filtrar pontos colineares e redundantes
    int m = 1; // 'm' é o índice para armazenar pontos não colineares

    // Loop para iterar sobre todos os pontos ordenados
    for (int i = 1; i < n; i++)
    {
        // Enquanto estamos dentro do limite de pontos
        // e os três pontos consecutivos (pontoInicial, pontos[i], pontos[i+1]) são colineares,
        // continuamos avançando o índice 'i'
        while (i < n - 1 && orientacao(pontoInicial, pontos[i], pontos[i + 1]) == 0)
            i++; // Avança 'i' para pular pontos colineares

        // Depois de sair do loop, armazenamos o ponto atual na posição 'm'
        // 'm' é o índice de inserção para os pontos não colineares
        pontos[m] = pontos[i];

        // Incrementamos 'm' para o próximo índice disponível
        m++;
    }

    // Se o número de pontos após a filtragem for menor que 3,
    // então não é possível formar um fecho convexo
    // (pelo menos 3 pontos são necessários para formar um polígono)
    if (m < 3)
    {
        return;
    }
    // Usar uma pilha para construir o fecho convexo
    stack<ponto> pilha;
    pilha.push(pontos[0]); // Primeiro ponto, aquele q está com min(y)
    pilha.push(pontos[1]); // coloca o segundo ponto.
    pilha.push(pontos[2]); // terceiro ponto, agora verica seu angulol.

    // Processar os pontos restantes
    for (int i = 3; i < m; i++)
    {
        // Remover pontos que não formam uma orientação anti-horária
        // Enquanto a pilha tiver pelo menos 2 elementos, E a orientacao de 2º da Pilha, 1º pilha (AB), e a (BC)
        // tiverem orientação anti-horária TIRA da pilha
        while (pilha.size() > 1 && orientacao(proximoTopo(pilha), pilha.top(), pontos[i]) != 2)
            pilha.pop();
        pilha.push(pontos[i]); // adiciona o ponto na pilha e repete.
    }

    // impressao
    stack<ponto> pilhaAns;
    while (!pilha.empty())
    {
        pilhaAns.push(pilha.top());
        pilha.pop();
    }

    cout << pilhaAns.size() << endl;
    while (!pilhaAns.empty())
    {
        ponto p = pilhaAns.top();
        cout << p.x << " " << p.y << "\n";
        pilhaAns.pop();
    }
}

int main()
{
    int cases;
    while (cin >> cases)
    {
        if (cases == 0)
        {
            break;
        }

        for (int i = 0; i < cases; i++)
        {
            int x, y;
            cin >> x >> y;
            pontos.push_back({x, y});
        }

        // execute and print convex hull
        fechoConvexo();
        pontos.clear();
    }

    return 0;
}
