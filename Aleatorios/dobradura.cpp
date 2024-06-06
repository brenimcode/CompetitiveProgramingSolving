#include <bits/stdc++.h>


using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

int32_t main()
{
    _
    int n, razao;
    int t = 1, qtd = 0;
    while (cin >> n)
    {
        if (n == -1)
            break;
        printf("Teste %lld\n", t++);
        razao = 0;
        for (int i = 0; i < n; i++)
        {
            razao += pow(2, i);
        }
        qtd = pow(2 + razao, 2);
        printf("%lld\n\n", qtd);
    }

    return 0;
}
