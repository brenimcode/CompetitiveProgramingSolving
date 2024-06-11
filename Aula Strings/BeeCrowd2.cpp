#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Lendo o número de casos de teste
    cin.ignore(); // Ignorando o caractere de nova linha após o número

    // Loop para cada caso de teste
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str); // Lendo a linha de entrada

        int num1 = 0, num2 = 0, num3 = 0;
        // Usando sscanf para extrair diretamente os três números da string
        sscanf(str.c_str(), "%d%*[^0-9]%d%*[^0-9]%d", &num1, &num2, &num3);

        // Calculando a soma dos três números
        int somaTotal = num1 + num2 + num3;

        // Imprimindo a soma total
        cout << somaTotal << endl;
    }

    return 0; // Indicando que o programa terminou com sucesso
}
