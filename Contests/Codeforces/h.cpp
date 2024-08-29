#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long

int32_t main() {
    _
    int n;
    cin >> n;

    set<int> res;
    res.insert(-5*n);
    res.insert(2*n);
    res.insert(0);

    cout << res.size() << endl;
    for (auto x : res)
    {
        cout << x << ' ';
    }
    


    return 0;
}
