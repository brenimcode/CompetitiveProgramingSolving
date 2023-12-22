#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, i, j, cont = 0;
    cin >> m >> n;
    char mapa[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> mapa[i][j];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mapa[i][j] == '#')
            {
                if (i == 0 || i == n - 1 || j == 0 || j == n-1)
                    cont++;
                else if (mapa[i][j - 1] == '.' || mapa[i][j + 1] == '.' || mapa[i - 1][j] == '.' || mapa[i + 1][j] == '.')
                    cont++;
            }
        }
    }
    cout << cont;

    return 0;
}