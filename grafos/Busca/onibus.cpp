#include <bits/stdc++.h>
using namespace std;

#define NMAX 10010

int n, ori,dest;
vector<int> grafo[NMAX];
int dist[NMAX];

void bfs(int start) {
    for (int i = 0; i <= n; i++)
    {
        dist[i] = -1;
    }

    queue<int> fila;
    dist[start] = 0;
    fila.push(start);

    while (!fila.empty()) {
        int vAtual = fila.front();
        fila.pop();

        for (int vViz : grafo[vAtual]) {
            if (dist[vViz] == -1) {
                dist[vViz] = dist[vAtual] + 1;
                fila.push(vViz);
            }
        }
    }
}

int main() {
    cin >> n >> ori >> dest;

    for (int i = 1; i <= n-1; i++) {
        int a,b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    bfs(ori);

    cout << dist[dest] << endl;

    return 0;
}
