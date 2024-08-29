#include <bits/stdc++.h>

using namespace std;

int main() {
    char o;
    cin >> o;

    long double mat[12][12];

    // Leitura da matriz 12x12
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> mat[i][j];
        }
    }

    long double sum = 0.0;
    long double count = 0.0;

    // Calcula a soma dos elementos acima da diagonal principal
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            sum += mat[i][j];
            count++;
        }
    }

    // Exibe a soma ou a média
    if (o == 'S')
        printf("%.1Lf\n", sum);
    else
        printf("%.1Lf\n", sum / count);

    return 0;
}
