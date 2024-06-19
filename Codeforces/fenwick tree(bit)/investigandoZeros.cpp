#include <bits/stdc++.h>
using namespace std;

int main() {
    int tamanho, elemento;
    int prefixos[2] = {1, 0}; // prefixos[0] = número de prefixos com número par de 1s
                             // prefixos[1] = número de prefixos com número ímpar de 1s
    cin >> tamanho;

    int mascara = 0;        // variável para armazenar a paridade acumulada de 1s
    long long resultado = 0; // variável para armazenar a quantidade de subvetores com número ímpar de 1s

    // Itera sobre cada elemento da sequência
    for (int i = 1; i <= tamanho; i++) {
        cin >> elemento; // Lê o próximo elemento da sequência
        mascara ^= elemento; // Atualiza a máscara usando XOR com o elemento atual
        
        // Adiciona ao resultado a quantidade de prefixos que têm a paridade oposta à da máscara atual
        resultado += prefixos[mascara ^ 1];
        
        // Atualiza a contagem de prefixos com a paridade atual
        prefixos[mascara] += 1;
    }

    // Exibe o resultado final
    cout << resultado << endl;

    return 0;
}
