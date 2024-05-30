#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 105
#define KMAX 100010
#define int long long

int n,k;
int diarias[KMAX];
int somas[KMAX];

bool funcao(int a, int b){
    return a > b;
}

int32_t main()
{
    cin >> n >> k;
    vector<int> filaOrdenada;
    for (int i = 0; i < n; i++)
    {

        int a,b;
        int resto;
        cin >> a >> b;
        resto = a%b;
        filaOrdenada.push_back(resto);
    }
    sort(filaOrdenada.begin(),filaOrdenada.end());

    

    cout << filaOrdenada[k-1] << endl;

}