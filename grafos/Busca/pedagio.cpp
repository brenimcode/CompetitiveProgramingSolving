#include <bits/stdc++.h>
using namespace std;

#define NMAX 10010

int n, m, l ,p;
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

    set<int> result;

    while (!fila.empty()) {
        int vAtual = fila.front();
        fila.pop();

        for (int vViz : grafo[vAtual]) {
            if (dist[vViz] == -1) {
                dist[vViz] = dist[vAtual] + 1;
                if(dist[vViz] <= p){
                    result.insert(vViz);
                } 
                fila.push(vViz);
            }
        }
    }


    for(auto it : result){
        cout << it << " ";
    }

}

int main() {
    int teste = 1;
    while(cin >> n >> m >> l >> p){
        if(n == m && m == l && l == p && p == 0){
            break;
        }
        // l == origem, p = qtd de pedagios 
        cout << "Teste " << teste++ << endl;
        
        for (int i = 1; i <= m; i++) {
            int a,b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        bfs(l);
        cout << endl << endl;

        for (int i = 0; i <= n; i++) {
            grafo[i].clear();
        }

    }
    return 0;
}
