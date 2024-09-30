#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, str2;
    getline(cin, str);
    getline(cin, str2);

    reverse(str2.begin(), str2.end());

    if (str == str2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}