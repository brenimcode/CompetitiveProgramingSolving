#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j;
    int n, m, s; // n = min, m = max, s = soma digitos

    cin >> n >> m >> s;
    bool ver = 0;
    for (i = m; i >= n; i--)
    {

        // Transformar INT -> STRING, SOMA ALGARISMOS
        string aux;
        aux = to_string(i);
        int sum = 0;
        for (j = 0; j < (int)aux.size(); j++)
        {
            sum +=  (aux[j] - '0');
            if(sum > s) {
                break;
            }
        }
        if (sum == s)
        {
            ver = 1;
            break;
        }
    }
    if (ver)
    {
        cout << i << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}