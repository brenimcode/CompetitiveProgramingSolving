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
    int i, j;
    for(i=1,j=0;i<=46;i+=2,j+=2){   
        printf("a = %d <-> b = %d\n",j,i);
        printf("a = %d <-> b = %d\n",j,++i);
    }
    return 0;
}