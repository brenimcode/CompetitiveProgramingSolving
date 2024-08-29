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
    int v[3];
    cin >> v[0] >> v[1] >> v[2]; // se a maquina estiver dist = 2, 4 min, dist=1, 2min, dist=0 0 min
    int menor = v[1]*2+v[2]*4; //caso 0
    if(menor > v[0]*2 + v[2]*2)
        menor = v[0]*2 + v[2]*2;
    if(menor > v[1]*2+v[0]*4)
        menor = v[1]*2+v[0]*4;


        cout << menor;
    return 0;
}