#include <iostream>
#include <vector>

using namespace std;

vector<int> permutation;
bool chosen[10]; // Assumindo um tamanho máximo de conjunto como 9

void search(int n) {
    if (permutation.size() == n) {
        // Processar ou imprimir a permutação
        cout << "(";
        for (int i = 0; i < permutation.size(); ++i) {
            cout << permutation[i];
            if (i < permutation.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(n);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Digite o valor de n: ";
    cin >> n;

    cout << "Todas as permutações de {1, 2, ..., " << n << "} são:\n";
    search(n);

    return 0;
}
