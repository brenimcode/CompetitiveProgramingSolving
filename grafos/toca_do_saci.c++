#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j, cont = 1, linha, coluna;
    cin >> n >> m;
    int matriz[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
            if (matriz[i][j] == 3)
            {
                linha = i;
                coluna = j;
            }
        }
    }
    i = linha;
    j = coluna;
    while (true)
    {
        // quando achar o caminho, ver =0
        if (j - 1 >= 0 && matriz[i][j - 1] == 1)
        {
            // <<
            matriz[i][j] = 0;
            j--;
            cont++;
        }
        else if (i + 1 >= 0 && matriz[i + 1][j] == 1)
        {
            // ^^
            matriz[i][j] = 0;
            i++;
            cont++;
        }
        else if (j + 1 < m && matriz[i][j + 1] == 1)
        {
            // >>
            matriz[i][j] = 0;
            j++;
            cont++;
        }
        else if (i - 1 < n && matriz[i - 1][j] == 1)
        {
            // vv
            matriz[i][j] = 0;
            i--;
            cont++;
        }
        else
        {
            if ((j + 1 < m && matriz[i][j + 1] == 2) || (j - 1 >= 0 && matriz[i][j - 1] == 2) || (i + 1 < n && matriz[i + 1][j] == 2) || (i - 1 >= 0 && matriz[i - 1][j] == 2))
            {
                cout << cont + 1;
                return 0;
            }
            else
            {
                matriz[i][j] = 0;
                cont = 1;
                i = linha;
                j = coluna;
            }
        }
    }

    return 0;
}