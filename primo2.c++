#include <bits/stdc++.h>

using namespace std;

vector <bool> e_composto(12000000,false);

void crivo(int n)
{
    int i,j;
    e_composto[1] = 1; // 1 não é composto, mas o vetor na verdade guarda os números que não são primos
    for ( i = 2; i <= n; ++i)
    {
        if (!e_composto[i])
        {
            for ( j = 2; j * i <= n; ++j)
            {
                e_composto[i * j] = 1;
            }
        }
    }
}

int main()
{
    int  i,cont=1,q;
    cin >> q;
    crivo(12000000);
    if(q == 1){
        cout << 2 << ' ';
        return 0;
    }
    for (i = 3; i <= 12000000; i+=2)
    {
        if (!e_composto[i])
            cont++;
        if(cont == q){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}
