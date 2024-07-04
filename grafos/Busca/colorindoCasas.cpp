#include <bits/stdc++.h>
using namespace std;

#define NMAX 100010
int n;
vector<int> grafo[NMAX];
int cor[NMAX]; // 1 == blue 


void debugGrafo() {
    for (int i = 1; i <= n; i++) {
        cout << "Vértice " << i << ":";
        for (auto viz : grafo[i]) {
            cout << " " << viz;
        }
        cout << endl;
    }
}

void debugCores() {
    for (int i = 1; i <= n; i++) {
        string color;
        switch (cor[i]) {
            case 0: color = "não visitado"; break;
            case 1: color = "blue"; break;
            case 2: color = "red"; break;
        }
        cout << "Vértice " << i << " - Cor: " << color << endl;
    }
}

bool bfs(int start)
{
    for (int i = 1; i <= n; i++)
    {
        cor[i] = 0; // nao foi visitado ainda
    }
    cor[start] = 1;
    queue<int> fila; // fila para os vertices
    fila.push(start);

    while (!fila.empty())
    {
        int atual = fila.front();
        fila.pop();

        for (auto viz : grafo[atual])
        {
            if (cor[viz] == 0)
            {
                int color = cor[atual];
                if (color == 1)
                    color = 2;
                else
                    color = 1;
                cor[viz] = color;
                fila.push(viz);
            }
            else if (cor[viz] == cor[atual])
            {
                return false;
            }
            
        }
    }

    int blue = 0;
    int red = 0;
    for (int i = 1; i <= n; i++){
        
        if(cor[i] == 1){
            blue++;
        }
        else if (cor[i] == 2){
            red++;
        }

    }

    return blue == red;

}

int main()
{
    cin >> n;
    int vez = n;
    while (--vez)
    {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    if (bfs(1))
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }


    return 0;
}

/*

8
1 2
2 3
3 5
1 4
2 6
6 7
8 1

*/