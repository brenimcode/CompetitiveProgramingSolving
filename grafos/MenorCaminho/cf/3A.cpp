#include <bits/stdc++.h>

using namespace std;

#define INF 1e5
#define MAX_N 68
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

const int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1}; // Movimento em x
const int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1}; // Movimento em y
// D,U,L,R,DL,DR,UL,UR

const unordered_map<int, string> moveMap = {
    {0, "D"},  // Baixo
    {1, "U"},  // Cima
    {2, "L"},  // Esquerda
    {3, "R"},  // Direita
    {4, "LD"}, // Baixo-Esquerda
    {5, "RD"}, // Baixo-Direita
    {6, "LU"}, // Cima-Esquerda
    {7, "RU"}  // Cima-Direita
};

int grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N]; // Usando vetor estático para distâncias
pair<int, int> pred[MAX_N][MAX_N]; // Predecessores para reconstruir o caminho
int moveTaken[MAX_N][MAX_N]; // Movimento feito para chegar a um nó
int n = 8, m = 8;

struct Node
{
    int dist;
    int x;
    int y;

    bool operator>(const Node &other) const
    {
        return dist > other.dist;
    }
};

void dijkstra(int startX, int startY)
{
    // Inicializar distâncias com INF e predecessores como inválidos
    for (int i = 0; i <= n + 5; ++i)
    {
        for (int j = 0; j <= m + 5; ++j)
        {
            dist[i][j] = INF;
            pred[i][j] = {-1, -1}; // Sem predecessor inicialmente
            moveTaken[i][j] = -1;  // Sem movimento inicial
        }
    }
    dist[startX][startY] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> fila;
    fila.push({0, startX, startY});

    while (!fila.empty())
    {
        Node atual = fila.top();
        fila.pop();

        if (atual.dist > dist[atual.x][atual.y])
            continue;

        for (int i = 0; i < 8; ++i)
        {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                int nd = atual.dist + grid[nx][ny];
                if (nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    fila.push({nd, nx, ny});
                    pred[nx][ny] = {atual.x, atual.y}; // Salva o predecessor
                    moveTaken[nx][ny] = i; // Salva qual movimento foi feito para chegar
                }
            }
        }
    }
}

// Função para reconstruir o caminho
vector<string> reconstructPath(int endX, int endY, int startX, int startY)
{
    vector<string> path;
    int cx = endX, cy = endY;

    while (cx != startX || cy != startY) // Enquanto não retornar ao ponto inicial
    {
        int moveIndex = moveTaken[cx][cy]; // Movimento feito para chegar aqui
        path.push_back(moveMap.at(moveIndex-2)); // Adiciona ao caminho
        // Move para o predecessor
        auto [px, py] = pred[cx][cy];
        cx = px;
        cy = py;
    }

    reverse(path.begin(), path.end()); // Inverter para obter o caminho correto
    return path;
}

int main()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            grid[i][j] = 1; // Todos os custos iguais a 1
        }
    }

    int iniX, iniY;
    string str;
    getline(cin, str);
    iniX = str[0] - 'a' + 1;
    iniY = str[1] - '0';
    getline(cin, str);
    int fimX = str[0] - 'a' + 1;
    int fimY = str[1] - '0';

    dijkstra(iniX, iniY); // Executa Dijkstra a partir do ponto inicial

    cout << dist[fimX][fimY] << endl; // Custo da menor rota

    vector<string> caminho = reconstructPath(fimX, fimY, iniX, iniY);
    for (auto &step : caminho)
    {
        cout << step << endl; // Imprime cada movimento no caminho
    }

    return 0;
}
