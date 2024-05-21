#include <iostream>
#include <vector>

using namespace std;

vector<int> subset; // Vetor para armazenar o subconjunto atual
int n; // Variável global para o tamanho do conjunto

void search(int k) {
    if (k == n + 1) {
        // Processar ou imprimir o subconjunto
        cout << "{ ";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
    } else {
        // Incluir k no subconjunto
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        // Não incluir k no subconjunto
        search(k + 1);
    }
}

int main() {
    cout << "Digite o valor de n: ";
    cin >> n;

    cout << "Todos os subconjuntos de 1 a " << n << " são:\n";
    search(1);

    return 0;
}
