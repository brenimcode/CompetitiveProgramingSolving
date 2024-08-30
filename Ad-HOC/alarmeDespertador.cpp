/*
beecrowd | 1103
Alarme Despertador
Maratona de Programação da SBC  Brasil


*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main()
{

    int h1, m1, h2, m2;

    while (cin >> h1 >> m1 >> h2 >> m2)
    {
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break; // Termination case

        // Calculate total minutes from midnight for both times
        int start = h1 * 60 + m1;
        int end = h2 * 60 + m2;

        // If the end time is earlier, it means it crosses midnight
        if (end <= start)
            end += 24 * 60;

        int ans = end - start;
        cout << ans << endl;
    }

    return 0;
}
