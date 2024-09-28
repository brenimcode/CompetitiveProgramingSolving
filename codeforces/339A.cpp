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

    for (int i = 0; i < (int) str.size(); i++)
    {
        if (str[i] != '+')
        {
            str2 += str[i];
        }
    }
    string str3 = str2;

    sort(str2.begin(), str2.end());

    if (str2 == str3)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = 0; i < (int) str2.size() - 1; i++)
        {
            cout << str2[i];
            cout << '+';
        }
        cout << str2[str2.size() - 1];
    }
}
