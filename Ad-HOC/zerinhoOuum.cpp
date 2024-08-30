/*
beecrowd | 1103

*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main()
{

    bool a, b, c;

    while (cin >> a >> b >> c)
    {
        if (a == b && c != a)
        {
            cout << "C" << endl;
        }
        else if (a == c && b != a)
        {
            cout << "B" << endl;
        }
        else if (b == c && b != a)
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }

    return 0;
}
