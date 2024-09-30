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
    int sum = 0;
    int maior = 0;
    while(n--) {
        int a,b;
        cin >> a >> b;
        sum-=a;
        sum+=b;
        if(maior < sum) {
            maior = sum;
        }
    }
    cout << maior << endl;

}