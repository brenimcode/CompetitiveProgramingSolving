/*
Carnaval - OBI 2012 - Segunda Fase
*/

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

// Trans
int32_t main()
{
    double a;
    int n;
    cin >> n;
    set<int> nums;
    while (n--)
    {
        cin >> a;
        nums.insert(a);
    }

    cout << nums.size() <<  endl;

    return 0;
}
