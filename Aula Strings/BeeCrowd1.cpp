#include <bits/stdc++.h>
using namespace std;

// Macro para ajudar na depuração do código, imprimindo o valor de uma variável
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int main() {
    int n;
    // Lendo o número de casos de teste
    cin >> n;
    // Ignorar o 'ENTER' do BUFFER
    cin.ignore();
    

    for (int i = 0; i < n; i++) {
        vector<string> substrings; // Vetor para armazenar os números encontrados na string
        string str;
        getline(cin, str);
        string numeroAtual = ""; // String temporária para construir números a partir dos dígitos
        
        // Loop através de cada caractere da string
        for (char c : str) {
            // Se já encontramos 3 números, podemos parar de procurar
            if (substrings.size() == 3) break;
            
            // Verificando se o caractere atual é um dígito (número)
            if (isdigit(c)) {
                // Se for um dígito, adicionamos ao número atual
                numeroAtual += c;
            } else {
                // Se não for um dígito, verificamos se temos um número para adicionar ao vetor
                if (!numeroAtual.empty()) {
                    substrings.push_back(numeroAtual);
                    numeroAtual = ""; // Limpamos a string temporária para o próximo número
                }
            }
        }

        // Após o loop, verificamos se há um número que ainda não foi adicionado ao vetor
        if (!numeroAtual.empty()) {
            substrings.push_back(numeroAtual);
        }

        int somaTotal = 0; // Variável para armazenar a soma total dos números
        
        // Transformando as strings em inteiros e somando
        for (string numStr : substrings) {
            int num = stoi(numStr); // Função que converte string para inteiro
            somaTotal += num; // Somando o número à soma total
        }

        // Imprimindo a soma total para o caso de teste atual
        cout << somaTotal << endl;
    }
    return 0; // Indicando que o programa terminou com sucesso
}
