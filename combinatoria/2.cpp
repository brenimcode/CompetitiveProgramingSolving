#include <bits/stdc++.h>

using namespace std;

long long int fatorial(long long int n)
{
    if (n == 0 || n == 1)
        return 1;
    long long int i;

    for (i = n - 1; i > 0; i--)
    {
        n *= i;
    }
    return n;
}

int main()
{
    long long int n, z,resultado,aux;
    while (cin >> n >> z)
    {
        if (n == 0 && z == 0)
            break;
        resultado = n;
        aux = n;
        while (aux > n - z+1)
        {
            resultado *= (aux - 1);
            aux--;
        }
        resultado /= fatorial(z);
        cout << resultado << endl;
    }

    return 0;
}
