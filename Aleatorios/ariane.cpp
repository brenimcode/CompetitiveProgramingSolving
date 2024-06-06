#include <bits/stdc++.h>

using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define int long long

int32_t main()
{
    _ int n, m, p;
    cin >> n >> m >> p;

    for (int jogos = 0; jogos < p; jogos++)
    {
        int ari = 0, ane = 0, aux;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> aux;
                if (aux == 1)
                {
                    ane++;
                }
                else
                {
                    ari++;
                }
            }
        }

        if (ari > ane)
        {
            printf("Ari venceu\n");
        }
        else if (ari < ane)
        {
            printf("Ane venceu\n");
        }
        else
        {
            printf("Empate\n");
        }
    }

    return 0;
}
