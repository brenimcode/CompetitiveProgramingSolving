#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,h;
    cin >> n >> h;
    int largura = 0;
    while(n--) {
        int aux;
        cin >> aux;
        if(aux <= h) {
            largura++;
        }
        else{
            largura+=2;
        }
    }

    cout << largura << endl;


}