#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long

int32_t main() {
    _

    int vet[10];
    int menor = 101;
    for (int i = 0; i < 10; i++)
    {
        cin >> vet[i];
        if(vet[i] < menor){
            menor = vet[i];
        }
    }
    printf("Menor: %lld\n",menor);
    printf("Ocorrencias: ");
    for (int i = 0; i < 10; i++)
    {
        if(vet[i] == menor){
           printf("%lld ",i);
            vet[i] = -1;
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%lld ",vet[i]);
    }
    printf("\n");

    
    return 0;
}
