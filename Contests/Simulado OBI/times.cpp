#include <bits/stdc++.h> // Importa todas as bibliotecas padrão do C++ de uma vez
using namespace std;

#define aluno pair<int,string> // {HABILIDADE, NOME}


int main() {
    int numAlunos, numTimes, timeAtual = 0;

    // Lê o número de alunos e o número de times
    cin >> numAlunos >> numTimes;

    // Vetor para armazenar pares de habilidade e nome dos alunos
    vector<aluno> alunos;
    
    // Vetor de vetores de string para armazenar os times
    vector<vector<string>> times(numTimes);

    // Lê os dados dos alunos e armazena no vetor de pares
    for (int i = 0; i < numAlunos; i++) {
        string nome;
        int habilidade;
        cin >> nome >> habilidade;
        alunos.push_back({habilidade, nome});
    }

    // Ordena os alunos por habilidade (crescente)
    sort(alunos.begin(), alunos.end());

    // Distribui os alunos para os times
    for (int i = numAlunos - 1; i >= 0; i--) {
        if (timeAtual == numTimes) {
            timeAtual = 0; // Reseta o contador de times se atingir o limite
        }
        
        times[timeAtual].push_back(alunos[i].second);
        timeAtual++;
    }

    // Imprime os times
    for (int i = 0; i < numTimes; i++) {
        // Ordena os nomes dos alunos dentro de cada time
        sort(times[i].begin(), times[i].end());
        // Imprime o número do time
        cout << "Time " << i + 1 << endl;

        // Imprime os nomes dos alunos do time
        for (string nome : times[i]) {
            cout << nome << endl;
        }

        cout << endl; // Linha em branco após cada time
    }

    

    return 0;
}
