#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        if ((q - p) > 1)
        {
            sum++;
        }
    }

    cout << sum << endl;
}