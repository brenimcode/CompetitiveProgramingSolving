#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

int N;
int valores[MAXN];
int melhor_prefixo[MAXN + 1]; // Melhor soma prefixa até o índice i
int soma_acumulada[MAXN + 1]; // Soma acumulada dos valores até o índice i

int main() {
    // Lendo o número de elementos
    cin >> N;

    // Lendo os valores dos elementos
    for (int i = 0; i < N; i++) {
        cin >> valores[i];
    }

    // Calculando a soma acumulada dos valores e a melhor soma prefixa
    soma_acumulada[0] = 0;
    melhor_prefixo[0] = 0;
    for (int i = 0; i < N; i++) {
        soma_acumulada[i + 1] = soma_acumulada[i] + valores[i];
        melhor_prefixo[i + 1] = max(melhor_prefixo[i], soma_acumulada[i + 1]);
    }

    // Calculando a melhor soma global considerando fatias que cruzam o ponto onde a lista é circular
    int melhor_global = 0;
    for (int i = 0; i <= N; i++) {
        int soma_fatia = soma_acumulada[N] - soma_acumulada[i]; // Soma dos elementos após o índice i
        melhor_global = max(melhor_global, melhor_prefixo[i] + soma_fatia);
    }

    // Verificando a melhor soma local em cada posição para garantir que fatias negativas sejam ignoradas
    int melhor_local = 0;
    for (int i = 0; i < N; i++) {
        melhor_local = max(0, melhor_local + valores[i]);
        melhor_global = max(melhor_global, melhor_local);
    }

    // Imprimindo a melhor soma global
    cout << melhor_global << endl;

    return 0;
}