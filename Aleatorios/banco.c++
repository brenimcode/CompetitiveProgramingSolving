#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    queue<pair<int, int>> fila;
    int c, n, i, aux1, aux2, cont = 0; // C é numero de CAIXAS, N é numero de Pessoas na fila
    cin >> c >> n;
    
    priority_queue<int, vector<int>, greater<int>> caixas;
    for (i = 0; i < c; i++) {
        caixas.push(0);
    }

    for (i = 0; i < n; i++) {
        cin >> aux1 >> aux2;
        fila.push(make_pair(aux1, aux2));
    }

    while (!fila.empty()) {
        // enquanto a fila nao for vazia, pega o primeiro da fila e coloca em um dos C caixas, e faça as operações
        for (i = 0; i < c && !fila.empty(); i++) {
            int inicio_atendimento = caixas.top(); // tempo de inicio de atendimento do próximo cliente no caixa atual
            caixas.pop(); // removemos o tempo de inicio de atendimento atual
            if (inicio_atendimento > fila.front().first + 20) { // verifica se o cliente esperou mais de 20 minutos
                cont++;
            }
            int fim_atendimento = max(inicio_atendimento, fila.front().first) + fila.front().second; // calcula o tempo de término de atendimento do cliente atual
            caixas.push(fim_atendimento); // adiciona o tempo de término de atendimento do cliente atual na fila de caixas
            fila.pop(); // remove o cliente atual da fila
        }
    }

    cout << cont;
    return 0;
}


