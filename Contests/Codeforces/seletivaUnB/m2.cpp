#include <bits/stdc++.h>
using namespace std;

const int MAX_P = 1000000;
vector<int> count_divisors(MAX_P + 1, 0);

int main() {
    // Leitura da entrada
    int n;
    cin >> n;
    vector<int> performances(n);
    for (int i = 0; i < n; ++i) {
        cin >> performances[i];
    }

    // Zerar o vetor de contagem de divisores
    fill(count_divisors.begin(), count_divisors.end(), 0);

    // Contar os divisores para cada performance
    for (int p : performances) {
        for (int divisor = 1; divisor <= sqrt(p); ++divisor) {
            if (p % divisor == 0) {
                count_divisors[divisor]++;
                if (divisor != p / divisor) {
                    count_divisors[p / divisor]++;
                }
            }
        }
    }

    // Encontrar o maior divisor que aparece pelo menos 3 vezes
    int melhor_sigma = 1;
    for (int d = MAX_P; d >= 1; --d) {
        if (count_divisors[d] >= 3) {
            melhor_sigma = d;
            break;
        }
    }

    // Agora precisamos encontrar os índices dos três competidores
    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        if (performances[i] % melhor_sigma == 0) {
            indices.push_back(i + 1);
        }
        if (indices.size() == 3) {
            break;
        }
    }

    // Imprimir os índices do melhor trio
    for (int i = 0; i < 3; ++i) {
        cout << indices[i] << (i < 2 ? " " : "\n");
    }

    return 0;
}
