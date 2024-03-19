#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

const int MOD = 1e9 + 7; // 10^9 + 7
#define NMAX 1000

int n = NMAX;
int moedas[NMAX];
int memo[NMAX][NMAX];

//
int32_t main() {
    //FASTIO;

    int n,g,m,i,j;  // N - numero de pessoas, G - numero de pizzas de 8 pedaços, M numero de pizzas de 6 pedaços

    cin >> n >> g >> m;
    int result = (8*g)+(6*m) - n;
    if(result < 0) cout << 0;
    else cout << result;




    return 0;

}
