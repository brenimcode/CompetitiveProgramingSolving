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


int troco(int moeda_atual, int valor_trocar){
    //Base:
    if(valor_trocar == 0) return 0; //EU consegui trocar todas as moedas anteriores!
    if(moeda_atual == n) return INF;//ja rodei todas moedas atuais, agora preciso que isso retorne o maximo entre as moedas anteriores.
    if(memo[moeda_atual][valor_trocar] != -1) return memo[moeda_atual][valor_trocar];

    int resposta = INF;
    if(moedas[moeda_atual] <= valor_trocar) //eu posso usar essa moeda! Vou usar essa moeda.
        resposta = min(resposta, 1 + troco(moeda_atual,valor_trocar - moedas[moeda_atual])); // O minimo entre usar o resultado atual e pegar a mesma moeda

    //Nao pegar a moeda é melhor?

    resposta = min(resposta,troco(moeda_atual+1,valor_trocar));


    return memo[moeda_atual][valor_trocar] = resposta;
}

int32_t main() {
    //FASTIO;

    int m,i,j;

    cin >> n >> m;
    memset(memo,-1,sizeof memo);
    for(i=0;i<n;i++) cin >> moedas[i];
    int ans = 0;
    troco(0,m);

    for(i=1;i<m;i++){
            bool ver = 1;
        for(j=0;j<n;j++){
            if(troco(0,i) < INF){ver=0;break;}
        }
        if(ver) ans++;
    }

    cout << ans;




    return 0;

}
