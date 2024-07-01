#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    return mdc(b,a%b);
}

int sinfonia(int a,int b, int c){
    int aux = mdc(a,b);
    return mdc(aux,c);
}

int32_t main() {
    _
    int n;
    cin >> n;
    int res = 0;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    
    int a,b,c;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                printf("S = [%d,%d,%d]\n", vet[i],vet[j],vet[k]);
                int aux = res;
                res = max(aux,sinfonia(vet[i],vet[j],vet[k]));
                if(aux != res){ // sinfonia mudou
                    a = i; b = j; c = k;
                }
            }
        
        }
        
    }
    
    cout << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
   
    return 0;
}
