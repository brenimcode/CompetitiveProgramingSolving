#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int n, m;
    cin >> n >> m;
    int tipo2 = 2 * (n - 1);
    tipo2 += 2 * (m - 1);
    int tipo1 = (n * m) + (n - 1) * (m - 1);

    cout << tipo1 << endl
         << tipo2 << endl;
    return 0;
}
