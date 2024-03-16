#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, m, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m >> n;

        // Limpar o buffer de entrada
        cin.ignore();

        map <string, string> dicionario;

        // Leitura do dicionário
        for (int j = 0; j < m; j++) {
            string str1, str2;
            getline(cin, str1);
            getline(cin, str2);
            dicionario[str1] = str2;
        }
        map<string,string> ::iterator it;
        // Leitura e processamento das strings
        for (int j = 0; j < n; j++) {
            string str3;

            // Corrigir a leitura removendo caracteres indesejados do buffer
            getline(cin >> ws, str3);

            // Usar stringstream para extrair palavras da string
            istringstream stream(str3);
            string palavra;

            // Processar cada palavra
            while (stream >> palavra) {
                // Verificar se a palavra está no dicionário e imprimir o valor correspondente
                it = dicionario.find(palavra);
                if (it != dicionario.end()) {
                    cout << it->second << " ";
                } else {
                    cout << palavra << " ";
                }
            }

            cout << endl;
        }
    }

    return 0;
}
