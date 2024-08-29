#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    int resto = 0; // Inicializar o resto da divisão por 3
    int pot2 = 1; // Inicializar a potência de dois

    // Calcular o número representado pela string binária
    for (int i = N - 1; i >= 0; i--) {
        resto = (resto + (S[i] - '0') * pot2) % 3;
        pot2 = (pot2 * 2) % 3;
    }


    string winner = (resto == 0) ? "JULIA" : "GIOVANA";

    // Imprimir o nome do vencedor
    cout << winner << endl;

    return 0;
}
