#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    string vet;
    for(int i = 0;i<n;i++) {
        char aux;
        cin >> aux;
        vet.push_back(aux);
    }

    for(int j = 0; j < k;j++){

    for(int i = 0;i<n;i=i) {
        if(vet[i] == 'B' && vet[i+1] == 'G'){
            vet[i+1] = 'B';
            vet[i] = 'G';
            i+=2;
        }else{
            i++;
        }
    }

    }
    cout << vet << endl;





}