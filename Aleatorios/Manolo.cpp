#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    int n,q;

    cin >> n;
    int mat[n+5][n+5];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }   
    }
    
    cin >> q;  
    int a,b,c,d;
    int sum_cenouras = 0;
    for (int it = 0; it < q; it++)
    {
        cin >> a >> b >> c >> d; 
        
        
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i >= a && i <= c &&  j >= b && j <= d){
                sum_cenouras+= mat[i][j];
                mat[i][j] = 0;
            }
        }   
    }

    }

    cout << sum_cenouras << endl;
    

}