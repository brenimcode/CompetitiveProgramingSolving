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
    bool ver = false;
    while (n--)
    {
        int aux;
        cin >> aux;
        if (aux == 1)
            ver = 1;
    }

    if (ver)
    {
        cout << "HARD" << endl;
    }
    else
    {
        cout << "EASY" << endl;
    }
}