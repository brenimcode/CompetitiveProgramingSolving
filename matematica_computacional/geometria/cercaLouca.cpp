#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define ponto pair<int, int>
#define x first
#define y second
#define PI 3.1415

int32_t main()
{
    int n;
    cin >> n;
    int altura[n + 2], largura[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> altura[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> largura[i];
    }

    long double areaT = 0.0;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        long double larg = largura[i];
        long double alt1 = altura[j]; // 0 ,1 -> 1,2 ->
        long double alt2 = altura[j + 1];

        if (alt2 > alt1)
        {
            areaT += (larg * alt1) + (larg * (alt2 - alt1) / 2.0);
        }
        else{
             areaT += (larg * alt2) + (larg * (alt1 - alt2) / 2.0);
        }
    }

    printf("%.1Lf", areaT);

    return 0;
}
