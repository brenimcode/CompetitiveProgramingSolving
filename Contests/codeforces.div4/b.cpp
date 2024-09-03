#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define NMAX 105

int32_t main()
{
    int n;
    int t;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore();
        char mat[n][4];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> mat[i][j];
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (mat[i][j] == '#')
                {
                    cout << j + 1 << ' ';
                }
            }
        }

        cout << endl;
    }

    return 0;
}
