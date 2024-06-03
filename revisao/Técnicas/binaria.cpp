#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int N, M;
int m[maxn]; // comprimentos dos pães

// Função que verifica se é possível cortar pelo menos N fatias de tamanho x
bool ok(int x) {
    int soma = 0;
    for (int i = 1; i <= M; i++) {
        soma += (m[i] / x); // parte inteira de m[i] / x
    }
    return (soma >= N);
}

// Função para realizar a busca binária no intervalo [ini, fim]
int busca(int ini, int fim) {
    while (ini < fim) {
        int mid = (ini + fim + 1) / 2; // Calcula o ponto médio (arredondando para cima)
        if (ok(mid)) {
            ini = mid; // Se ok(mid) é verdadeiro, aumentamos o limite inferior
        } else {
            fim = mid - 1; // Se ok(mid) é falso, reduzimos o limite superior
        }
    }
    return ini; // Retorna o maior valor possível
}

int main() {
    // Leitura dos valores de N e M
    scanf("%d %d", &N, &M);

    // Leitura dos comprimentos dos pães
    for (int i = 1; i <= M; i++) {
        scanf("%d", &m[i]);
    }

    // Impressão da maior fatia possível encontrada
    printf("%d\n", busca(1, 10000));

    return 0;
}
