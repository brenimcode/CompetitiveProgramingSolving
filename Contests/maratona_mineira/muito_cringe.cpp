#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    int n;
    cin >> n;

    if(n <1980) printf("Geracao X!!!\n");
    if(n >= 1980 && n <1996) printf("Geracao Millennials. Muito cringe!!!\n");
    if(n >= 1996 && n <2011)printf("Geracao Z!!!\n");
    if(n >= 2011)  printf("Geracao Alpha!!!\n");

    return 0;
}