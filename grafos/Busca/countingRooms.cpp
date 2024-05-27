#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 1002

int dI[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
int n, m;
int num;
char mat[NMAX][NMAX];

void dfs(int i, int j)
{
    mat[i][j] = '$';

    for (int k = 0; k < 4; k++)
    {
        int vizI = i + dI[k];
        int vizJ = j + dj[k];

        if (vizI > n || vizI <= 0 || vizJ > m || vizJ <= 0)
            continue;

        if (mat[vizI][vizJ] == '.')
        {
            dfs(vizI, vizJ);
        }
    }
}

int main()
{

    cin >> n >> m;

    vector<pair<int, int>> pos;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '.')
            {
                pos.push_back(make_pair(i, j));
            }
        }
    }

    num = 0;
    for (int i = 0; i < (int)pos.size(); i++)
    {
        int i0, j0;
        i0 = pos[i].first;
        j0 = pos[i].second;
        if (mat[i0][j0] == '.')
        {
            num++;
            dfs(i0, j0);
        }
    }

    cout << num << endl;

    return 0;
}