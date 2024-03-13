#include <bits/stdc++.h>

using namespace std;

#define NMAX 202

typedef long long int ll;

ll qtd, mat[NMAX][NMAX], cor_atual, menor = 99999999, n, m;
bool marcados[NMAX][NMAX];

ll eixox[] = {0, 0, 1, -1};
ll eixoy[] = {1, -1, 0, 0};

bool dentro_do_limite(ll i, ll j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

void dfs(ll i, ll j)
{
    if (marcados[i][j] == true)
        return;
    marcados[i][j] = true;
    qtd++;
    ll X, Y;
    for (ll k = 0; k < 4; k++)
    { // Andar nas 4 direções
        X = i + eixox[k];
        Y = j + eixoy[k];
        // Assim rodando 4 vezes eu rodo todas as possiveis direçoes
        if (dentro_do_limite(X, Y) && mat[X][Y] == cor_atual && marcados[X][Y] == false)
            dfs(X, Y);
    }
}

int main()
{
    ll i, j;
    cin >> n >> m;
    // as peças sao de 1 a N

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> mat[i][j];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (marcados[i][j] == false)
            {
                qtd = 0;
                cor_atual = mat[i][j];
                dfs(i, j);
                if (qtd < menor)
                    menor = qtd;
            }
        }
    }
    cout << menor;

    return 0;
}