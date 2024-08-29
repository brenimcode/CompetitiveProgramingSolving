#include <bits/stdc++.h>

using namespace std;

#define NMAX 7
int best[NMAX];
int num[NMAX];

int rec(int i) {
    if (best[i] != -1) // Se o valor j� foi calculado, retorna o valor armazenado
        return best[i];

    best[i] = 1; // Inicializa o valor de best[i] com 1 (a pr�pria sequ�ncia de um elemento � uma subsequ�ncia crescente)

    for (int j = i + 1; j < NMAX; j++) { // Percorre os elementos seguintes na sequ�ncia
        if (num[j] > num[i]) // Se o elemento atual for maior que o elemento i
            best[i] = max(best[i], 1 + rec(j)); // Atualiza o valor de best[i] com o m�ximo entre seu valor atual e 1 + best[j]
    }

    return best[i]; // Retorna o valor calculado
}

int main() {
    int a;

    for (int i = 0; i < NMAX; i++) // L� nmax n�meros de sequ�ncia
        cin >> num[i];

    memset(best, -1, sizeof(best)); // Inicializa minha best[nmax] com -1 para aplicar programa��o din�mica

    int maxLength = 0;
    for (int i = 0; i < NMAX; i++) { // Calcula o comprimento da subsequ�ncia crescente mais longa iniciando em cada posi��o
        maxLength = max(maxLength, rec(i));
    }

    cout << maxLength << endl; // Imprime o comprimento da subsequ�ncia crescente mais longa

    return 0;
}
