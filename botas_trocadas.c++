#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, cont = 0, j;
    cin >> n;
    pair<int, char> botas[n];
    vector<bool> visitado(n, false);
    for (i = 0; i < n; i++)
    {
        cin >> botas[i].first;
        cin >> botas[i].second;
    }

    for (i = 0; i < n; i++)
    {
        if (!visitado[i])
        {
            for (j = 0; j < n; j++)
            {
                if (!visitado[j] && (botas[i].first == botas[j].first) && (botas[i].second != botas[j].second))
                {
                    cont++;
                    visitado[i] = 1;
                    visitado[j] = 1;
                }
            }
        }
    }
    cout << cont;
}