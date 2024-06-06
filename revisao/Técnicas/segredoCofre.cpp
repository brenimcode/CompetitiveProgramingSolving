#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100100 // Definição do tamanho máximo do vetor

// Função para atualizar a frequência no intervalo [inicio, fim] com incremento valor
void atualizarFrequencia(int frequencia[], int inicio, int fim, int valor) {
    frequencia[inicio] += valor;
    frequencia[fim + 1] -= valor;
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int numPosicoes, numMovimentos;
    cin >> numPosicoes >> numMovimentos;

    int barra[MAXN], frequencia[MAXN] = {0}; // Inicialização do vetor de frequências
    long long contagemDigitos[10] = {0};    // Inicialização do vetor de contagem de dígitos

    // Leitura da barra
    for (int i = 1; i <= numPosicoes; i++) {
        cin >> barra[i];
    }

    // Leitura da sequência de movimentos
    int sequenciaMovimentos[MAXN];
    for (int i = 1; i <= numMovimentos; i++) {
        cin >> sequenciaMovimentos[i];
    }

    int posicaoAtual = 1; // Posição inicial do controle
    atualizarFrequencia(frequencia, 1, 1, 1); // A primeira posição é contada inicialmente

    // Processamento dos movimentos
    for (int i = 1; i <= numMovimentos; i++) {
        int proximaPosicao = sequenciaMovimentos[i];
        int inicio = min(posicaoAtual, proximaPosicao);
        int fim = max(posicaoAtual, proximaPosicao);
        atualizarFrequencia(frequencia, inicio, fim, 1);
        atualizarFrequencia(frequencia, posicaoAtual, posicaoAtual, -1);
        posicaoAtual = proximaPosicao;
    }

    // Cálculo das frequências acumuladas
    for (int i = 1; i <= numPosicoes; i++) {
        frequencia[i] += frequencia[i - 1];
        contagemDigitos[barra[i]] += frequencia[i];
    }

    // Impressão da contagem de cada dígito de 0 a 9
    for (int i = 0; i < 10; i++) {
        cout << contagemDigitos[i] << " ";
    }
    cout << endl;

    return 0;
}
