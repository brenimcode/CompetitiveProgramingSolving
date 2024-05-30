#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 105

int dI[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1}; // (0) = (V), (1) = (A), (2) = (>) ,(3) = (<)

int n, m;
char mat[NMAX][NMAX];
bool ver;
char navio;
int tamanhoNavio[NMAX];

void dfs(int i, int j)
{
    
    for (int k = 0; k < 4; k++)
    {
        int vizI = i + dI[k];
        int vizJ = j + dj[k];

        if (vizI < 0 || vizI > n || vizJ < 0 || vizJ > m)
            continue;

        if (mat[vizI][vizJ] == navio)
        {   
            ver = 1;
            break;
        }

    }
}

void printa(){
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mat[i][j] << ' ';
            
        }
        cout << endl;
    }
}

int main()
{

    cin >> n >> m;

    vector<pair<int, int>> pos;


    for (int i = 1; i <= n; i++)
    {
        tamanhoNavio[i] = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            
        }
    }

    int k, a, b;
    cin >> k;

     sum = 0;
    char navio = 'A';
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b; // linha e coluna do ataque
        navio = 'A'+i;
        if (mat[a][b] == '#')
        {
            // Chama DFS para infectar os vizinhos
            ver = 0;
            mat[a][b] = navio;
            dfs(a, b);
            if(!ver){
                sum++;
            }
            
        }
    }

    

    cout << sum << endl;

    return 0;
}