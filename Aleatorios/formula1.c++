#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g, p, i, j, s, k, k1, l, l2,somaMaxima,somaColuna;

    while (1)
    {
        scanf("%d %d", &g, &p); // G é o numero de grandes premios e P numero de pilotos
        if (g == 0 && p == 0)
            break;
        pair<int, int> par[g][p];

        for (i = 0; i < g; i++)
        {
            for (j = 0; j < p; j++)
            {
                scanf("%d", &par[i][j].first);
                par[i][j].second = 0;
            }
        }
        cin >> s;
        for (i = 0; i < s; i++)
        {
            cin >> k;
            for (j = 0; j < k; j++)
            {
                cin >> k1;
                for (l = 0; l < g; l++)
                    for (l2 = 0; l2 < p; l2++)
                        if (par[l][l2].first == j + 1)
                            par[l][l2].second = k1;
            }

            somaMaxima = 0;
            vector<int> piloto_vencedor;

            // Iterando sobre as colunas
            for (j = 0; j < p; ++j)
            {
                somaColuna = 0;
                for (l = 0; l < g; ++l)
                {
                    somaColuna += par[l][j].second;
                    par[l][j].second = 0;
                }
                // Verificando se a soma da coluna atual é maior que a soma máxima
                if (somaColuna > somaMaxima)
                {
                    somaMaxima = somaColuna;
                    piloto_vencedor.clear(); // Limpa o vetor, pois encontramos uma nova maior soma
                    piloto_vencedor.push_back(j);
                }
                else if (somaColuna == somaMaxima)
                {
                    // Se a soma da coluna for igual à soma máxima, adiciona a coluna ao vetor
                    piloto_vencedor.push_back(j);
                }
            }

            for (l = 0; l < (int) piloto_vencedor.size(); l++)
                cout << piloto_vencedor[l] + 1 << " ";
            cout << endl;
        }
    }

    return 0;
}
