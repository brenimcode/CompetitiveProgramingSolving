#include <bits/stdc++.h>

using namespace std;

#define INF 1e5
#define MAX_N 1000

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];  // Usando vetor estático para distâncias
int n, m;

struct Node {
    int dist;
    int x;
    int y;

    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int startX, int startY) {
    // Inicializar distâncias com INF
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[startX][startY] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> fila;
    fila.push({0, startX, startY});

    while (!fila.empty()) {
        Node atual = fila.top();
        fila.pop();

        if (atual.dist > dist[atual.x][atual.y]) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nd = atual.dist + grid[nx][ny];
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    fila.push({nd, nx, ny});
                }
            }
        }
    }

    // Imprimir distâncias mínimas do ponto inicial para todos os pontos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int iniX, iniY;
    cin >> iniX >> iniY;

    dijkstra(iniX, iniY);

    return 0;
}
