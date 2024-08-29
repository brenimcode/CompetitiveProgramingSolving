#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int posicoes[m];
    for (int i = 0; i < m; i++) {
        cin >> posicoes[i];
    }
    
    int maior = 0;
    for (int i = 1; i < m; i++) {
        maior = max(maior, posicoes[i] - posicoes[i-1]);
    }
    
    // Calcular a distância do início da rua ao primeiro poste
    // e do último poste ao final da rua
    int distanciaInicio = posicoes[0] - 0;
    int distanciaFim = n - posicoes[m-1];
    
    int result = max({distanciaInicio, distanciaFim, (maior + 1) / 2});
    
    cout << result << endl;
    
    return 0;
}
