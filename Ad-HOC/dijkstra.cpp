/*
beecrowd | 2653

*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main()
{

    string str;
    set<string> joias;
    while (getline(cin,str))
    {
        joias.insert(str);
    }

    cout << joias.size() << endl;

    return 0;
}
