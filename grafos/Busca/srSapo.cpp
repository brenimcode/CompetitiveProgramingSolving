#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 103

int dI[12] = {1, -1, 0, 0,2, -2, 0, 0,3, -3, 0, 0};
int dj[12] = {0, 0, 1, -1,0, 0, 2, -2,0, 0, 3, -3};
int n, m, p;
int mat[NMAX][NMAX];
bool ver;

void dfs(int i, int j)
{
    mat[i][j] = 2;

    for (int k = 0; k < 12; k++)
    {
        int vizI = i + dI[k];
        int vizJ = j + dj[k];

        if (vizI > n || vizI <= 0 || vizJ > m || vizJ <= 0)
            continue;

        if(mat[vizI][vizJ] == 4){
            ver = 1;
            return;
        }
        if (mat[vizI][vizJ] == 1)
        {
            dfs(vizI, vizJ);
        }
    }
    

}

int main()
{

    cin >> n >> m;

    cin >> p;
    int a,b;

    for (int i = 1; i <= p; i++)
    {
        cin >> a >> b;
        mat[a][b] = 1;
    }
    int sc,sl;
    cin >> sc >> sl;
    mat[sc][sl] = 3; // Posição do SAPO
    cin >> a >> b;
    mat[a][b] = 4; // Posição da SAPA
    ver = 0;
    dfs(sc,sl);

    if(ver){
        cout << 'S' << endl;
    }else{
        cout << 'N' << endl;
    }

    return 0;
}