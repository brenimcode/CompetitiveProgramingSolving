#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl
typedef pair<int, int> par;

int main()
{
    int n, m;

    cin >> n >> m; // n é o dia, m é a semana

    if (n + (m*7) <= 30)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}
