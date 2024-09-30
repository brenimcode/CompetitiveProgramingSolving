#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int i = n;
    for(i = n+1;i <= 12000;i++){
        string a;
        a = to_string(i);
        if(a[0] != a[1] && a[0] != a[2] && a[0] != a[3] && a[1] != a[2] && a[1] != a[3] && a[2] != a[3])
            break;
    }
    cout << i << endl;

}