#include <bits/stdc++.h>

using namespace std;

#define NMAX 1010

bool grafo[NMAX][NMAX];

int main(){
   int a,b,i,j,k,x,y;

    cin >> a >> b;
    for(i=0;i<a;i++)
            for(j=0;j<a;j++)
                grafo[i][j] = false;


    for(i=0;i<b;i++){
        cin >> x >> y;
        grafo[x][y] = true;
        grafo[y][x] = true; //leitura do grafo.
    }

    int p,possiveis=0,n;
    bool ver;
    cin >> p; //qtd de SUGESTAO passeios

    for(i=0;i<p;i++){
        cin >> n;
        int passeios[n];
        for(j=0;j<n;j++){
            cin >> passeios[j];
        }
        ver = 1;
        for(j=0;j<n-1;j++){
                //printf("grafo[%d][%d]-[%d] ",passeios[j],passeios[j+1],grafo[passeios[j]][passeios[j+1]]);
            if(grafo[passeios[j]][passeios[j+1]] == false){
              ver = false;
              break;
            }
        }
        if(ver){
            possiveis++;
        }

    }
    cout << possiveis;
}
