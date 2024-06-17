#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 1002

int dI[4] = {1, -1, 0, 0}; // linha
int dj[4] = {0, 0, 1, -1}; // coluna

int n, m, a, b;
int x,y;
int mat[NMAX][NMAX];

void dfs(int i, int j)
{
    mat[i][j] = 2;
    int ver = 0;
    for (int k = 0; k < 4; k++)
    {
        int vizI = i + dI[k];
        int vizJ = j + dj[k];

        if (vizI > n || vizI <= 0 || vizJ > m || vizJ <= 0) // verificar se fora da matriz
            continue;

        if (mat[vizI][vizJ] == 1) // verifica se é um caminho valido
        {
            ver = 1;
            dfs(vizI, vizJ);
        }
    }
    if(ver == 0){
        x = i;
        y = j;
    }
}

int main()
{

    cin >> n >> m;

    vector<pair<int, int>> pos;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            
        }
    }
    
    x = 1, y = 1;
    dfs(a,b);

    cout << x << ' ' << y << endl;

    return 0;
}