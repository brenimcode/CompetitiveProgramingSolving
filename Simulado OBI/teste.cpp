#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++

using namespace std;

#define int long long // Define 'long long' como 'int'
#define NMAX 1000     // Tamanho máximo do vetor

int32_t main()
{                               
    int i, n; // Declaração das variáveis

    cin >> n;

    int sum1 = 0, sum2 = 0;
    int aux1, aux2;
    for (i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        sum1 += aux1;
        sum2 += aux2;
    }

    sum1 /= n;
    sum2 /= n;

    if (sum1 > sum2)
    {
        cout << ":0 <-X- Gohan e Feijao" << endl;
    }
    else if (sum1 < sum2)
    {
        cout << ":0 <- Gohan e Feijao" << endl;
    }
    else
    {
        cout << "Impasse" << endl;
    }

    return 0;
}
