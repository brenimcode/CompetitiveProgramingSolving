#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return mdc(b, a % b);
}

int sinfonia(int a, int b, int c)
{
    int aux = mdc(a, b);
    return mdc(aux, c);
}

int32_t main()
{
    _
    int n,res,maior = 1;
    cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        if (maior < vet[i])
        {
            maior = vet[i];
        }
    }

    int a = 0, b = 1, c = 2;
    // implementação na força bruta.
    res = sinfonia(vet[0], vet[1], vet[2]);

    for (int i = 0; i < n - 2; i++)
    {
        if (vet[i] == 1) // esse numero é o menor MDC possivel, logo ele nao será o maior.
        {
            continue;
        }
        for (int j = i + 1; j < n - 1; j++)
        {
            if (res >= mdc(vet[i], vet[j]) || vet[j] == 1)
            { // mdc(a,b) >= mdc(a,b,c) então, se res > mdc(a,b), res >= mdc(a,b,c)
                continue;
            }
            for (int k = j + 1; k < n; k++)
            {
                if(vet[k] == 1){ // mdc(a,b,1) = 1.
                    continue;
                }
               // printf("S = [%d,%d,%d]\n", vet[i], vet[j], vet[k]); // printa o subconjunto
                int aux = res;
                res = max(aux, sinfonia(vet[i], vet[j], vet[k]));
                if (aux != res)
                { // sinfonia mudou
                    a = i;
                    b = j;
                    c = k;
                }
                if (res == maior)
                { // achei o maior possivel! printar e parar.
                    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
                    return 0;
                }
            }
        }
    }

    // printando o indice dos melhores conjuntos:
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;

    return 0;
}
