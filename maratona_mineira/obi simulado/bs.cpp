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

    cin >> n;
    string a = "";
    char aux;
    vector<char> result;
    for(i=0;i<n;i++){
        cin >> aux;
        a+=aux;
    }
    int qtd;
     for(i=0;i<n;i++){
         qtd = 0;
         aux = a[i];
         for(j=i;j<n;j++){

                if(a[i] == a[j]) qtd++;
                else{
                        i = j-1;
                        break;
                }
         }
         printf("%d %c ",qtd,aux);
         if(j == n) return 0;
     }





    return 0;

}
