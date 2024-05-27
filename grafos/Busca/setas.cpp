#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 505

int dI[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1}; // (0) = (V), (1) = (A), (2) = (>) ,(3) = (<)
int n;
int sum;
char mat[NMAX][NMAX];
bool ver;

void dfs(int i, int j)
{

    char direction = mat[i][j];
    if(mat[i][j] != '.')
    {
        mat[i][j] = '#';
    } 
    int vizI = i, vizJ = j;

    if (direction == 'V')
    {
        vizI += 1;
    }
    else if (direction == 'A')
    {
        vizI -= 1;
    }
    else if (direction == '>')
    {
        vizJ += 1;
    }
    else if (direction == '<')
    {
        vizJ -= 1;
    }


    if (mat[vizI][vizJ] == '.')
    {
        ver = 1;
    }
    else if (mat[vizI][vizJ] != '#')
    {
        dfs(vizI, vizJ);
    }

    if(ver == 1){
        mat[i][j] = '.';
        sum++;
    }
        

}

int main()
{

    cin >> n;

    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if (i == 1 || j == 1 || i == n || j == n)
            {
                if ((i == 1 && mat[i][j] == 'A') || (j == 1 && mat[i][j] == '<') || (j == n && mat[i][j] == '>') || (i == n && mat[i][j] == 'V'))
                {
                    mat[i][j] = '.';
                    sum++;
                }
            }
        }
    }

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(mat[i][j] != '.' && mat[i][j] != '#'){
                ver = 0;
                dfs(i, j);
            }
        }
    }


    cout << (n * n) - sum << endl;

    return 0;
}