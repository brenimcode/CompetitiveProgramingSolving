#include <bits/stdc++.h>
using namespace std;

#define NMAX 10010
#define par pair<int,int>
int n,d;
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

bool alcanca(par atual,par viz){
    int x = atual.first;
    int y = atual.second;
    int a = viz.first;
    int b = viz.second;
    double val = sqrt(pow(x-a,2) + pow(y-b,2));
    if(val <= d){
        return true;
    }
    return false;
}

int main() {
    cin >> n >> d; // n é a qtd de cipos e d é o alcance dos cipos
    
    par vet[n]; // coord
    vet[0] = {0,0};
    for (int i = 1; i <= n; i++) {
        int a,b;
        cin >> a >> b; // {X,Y}
        vet[i] = {a,b};
    }


    for (int i = 1; i <= n; i++) {

        par atual = vet[i];
        for (int j = i; j <= n; j++)
        {
            par vizinho = vet[j];
            if(!alcanca(atual,vizinho)){
                cout << "N" << endl;
                return 0;
            }
        }

    }

    cout << "S" << endl;


    //bfs(ori);

  //  cout << dist[dest] << endl;

    return 0;
}
