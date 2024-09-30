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

    int a = 0, d = 0;
    while (n--)
    {
        char aux;
        cin >> aux;
        if (aux == 'A')
        {
            a++;
        }
        else
        {
            d++;
        }
    }

    if (a > d)
    {
        cout << "Anton" << endl;
    }
    else if (a < d)
    {
        cout << "Danik" << endl;
    }
    else
    {
        cout << "Friendship" << endl;
    }
}