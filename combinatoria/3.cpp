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
    string palavra;
    getline(cin, palavra);
    int consoantes = 0, vogais = 0, tam = palavra.size(), i, indice_letra;
    int anagrama[tam];
    vector < pair<char,int> > rep(26); //letra e sua qtd de vezes aparecida
    for (i = 0; i < 26; i++)
    { // colocando tds letras do alfabeto como 0, e anagrama[i] = 1 para fazer o produto ao final
        rep[i].first = i;
        rep[1].second = 0;
        if (i < tam)
        {
            anagrama[i] = 1;
        }
    }
    for (i = 0; i < tam; i++)
    {
        if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U')
        {
            vogais++;
        }
        else if (palavra[i] != ' ')
        {
            consoantes++;
        }
        indice_letra = palavra[i] - 'A';
        rep[indice_letra].second++;
    }

    long long int result = 1;
    for (i = 0; i < tam; i++)
    {
        if (i % 2 == 0)
        {
            if (consoantes > 0)
            {
                anagrama[i] *= consoantes;
                consoantes--;
            }
        }
        else
        {
            if (vogais > 0)
            {
                anagrama[i + 1] *= vogais;
                vogais--;
            }
        }
        result *= anagrama[i];
    }

    
    for (i = 0; i < 26; i++)
        if (rep[i].second > 1)
            result /= fatorial( (long long int) rep[i].second);

    printf("%lld\n", result);

    return 0;
}