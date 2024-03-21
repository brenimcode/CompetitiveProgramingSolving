#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

const int MOD = 1e9 + 7; // 10^9 + 7
#define NMAX 500

char mat[NMAX][NMAX];
int drow[4] = {0,1,0,-1};
int dcolum[4] ={-1,0,1,0}; //Movimentos esq,dir,cima,baixo
//
int n,f; // n é dimensao da matriz, e f é força da erupcao


void dfs(int i, int j) { //passo as coordenadas
    if(i==0 && j == 0){
        if(mat[i][j] > (char) f +48){
            return;
        }
    }
    mat[i][j] = '*';
    for(int k=0;k<4;k++){
        int vx = i + drow[k];
        int vy = j + dcolum[k];

        if(vx < 0 || vy < 0 || vx>=n || vy>=n) continue; //esta fora da matriz

        if(mat[vx][vy] <= (char) f +48 && mat[vx][vy] != '*'){dfs(vx,vy);} //força é maior que o dado valor, entao faça


    } // movimentos possiveis

}

int32_t main() {
    //FASTIO;

    int i,j;  // n = dimensao da matriz
    cin >> n >> f;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin >> mat[i][j];

    dfs(0,0);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << mat[i][j];
        }
        cout << endl;
    }



    return 0;

}
