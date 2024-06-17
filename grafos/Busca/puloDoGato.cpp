#include <bits/stdc++.h>
using namespace std;

#define NMAX 505
#define par pair<int,int>
#define INF 99999
int n, m, l, p;
int grafo[NMAX][NMAX];
int dist[NMAX][NMAX];



int main(){
    int i,j;
    cin >> n >> m;
    

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> grafo[i][j];
            dist[i][j] = INF;
        }
    }
    queue<par> fila;

    fila.push({1,1});
    dist[1][1] = 0;

    while(!fila.empty()){
        int l = fila.front().first;
        int c = fila.front().second;
        fila.pop();

        for(int dl=-2; dl<=2 ;dl++){
            for(int dc=-2 ; dc<=2 ;dc++){
                int l2 = l +dl;
                int c2 = c+dc;

                // esta dentro do limite da matz
                if(l2<=n && l2 >=1 && c2 <=m && c2 >=1 && dist[l2][c2] == INF && grafo[l2][c2] == 1){
                    dist[l2][c2] = dist[l][c]+1;
                    fila.push({l2,c2});
                }

                // ver se ja visitou.

            }
        }  
    }
    if(dist[n][m] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dist[n][m] << endl;
    }


    return 0;
}
