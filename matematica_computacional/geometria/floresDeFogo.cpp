#include <bits/stdc++.h>

using namespace std;
#define int long long

#define ponto pair<int, int>
#define x first
#define y second

int32_t main()
{
    long double r1, r2, x1, x2, y1, y2;

    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2)
    {
        // x1 = abs(x1); y1 = abs(y1); x2 = abs(x2); y2 = abs(y2);
        long double dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        
        if ( r1 >= r2 && dist <= (r1 - r2)*(r1 - r2) )
        {
            cout << "RICO" << endl;
        }
        else
        {
            cout << "MORTO" << endl;
        }
    }

    return 0;
}
