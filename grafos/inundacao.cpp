#include <bits/stdc++.h>

using namespace std;

#define NMAX 50

pair<int, int> explorados[2500];

void dfs(char mat[][NMAX], int linha, int coluna, int i, int j)
{
    if (i < linha && mat[i + 1][j] == 'A')
    {
        mat[i + 1][j] = 'T';
        dfs(mat, linha, coluna, i + 1, j);
        // Direita
    }
    if (i >= 0 && mat[i - 1][j] == 'A')
    {
        mat[i - 1][j] = 'T';
        dfs(mat, linha, coluna, i - 1, j);
        // Esquerda
    }
    if (j < coluna && mat[i][j + 1] == 'A')
    {
        mat[i][j + 1] = 'T';
        dfs(mat, linha, coluna, i, j + 1);
        // Baixo
    }
    if (j >= 0 && mat[i][j - 1] == 'A')
    {
        mat[i][j - 1] = 'T';
        dfs(mat, linha, coluna, i, j - 1);
        // Cima
    }
}

void vazamento(char mat[][NMAX], int linhas, int colunas, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++)
    {
        if (explorados[i] != make_pair(-1, -1))
            dfs(mat, linhas, colunas, explorados[i].first, explorados[i].second);
    }

    for (i = 0; i < qtd; i++)
    {
        explorados[i] = make_pair(-1, -1);
    }
}

int main()
{
    int n, i, j, m, k;
    while (1)
    {
        cin >> n >> m;
        k = 0;
        if (n == 0 && n == m)
            break;
        char mat[n][NMAX];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'T')
                {
                    explorados[k++] = make_pair(i, j);
                }
                else
                {
                    explorados[k++] = make_pair(-1, -1);
                }
            }
        }
        vazamento(mat, n, m, k);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    // A = Vazio, X = Rocha, T = Vazamento

    return 0;
}
