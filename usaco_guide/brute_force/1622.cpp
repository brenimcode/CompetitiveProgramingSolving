#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long

int32_t main()
{
    string str;
    getline(cin, str);
    vector<string> ans;
    sort(str.begin(), str.end());

    do
    {
        ans.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << ans.size() << endl;

    for (string &palavra : ans)
    {
        cout << palavra << endl;
    }

    return 0;
}
