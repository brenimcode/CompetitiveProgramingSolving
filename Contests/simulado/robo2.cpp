#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

#define NMAX 100005 // Ajustado para suportar até 100000
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);


int32_t main() {
    _

    int n, m;
    // Leitura do tamanho do tabuleiro
    cin >> n >> m;
    int k, l;

    // Conjuntos para armazenar os obstáculos em cada linha e coluna
    vector<set<int>> linha(NMAX+4); 
    vector<set<int>> coluna(NMAX+4);

    // Leitura da posição inicial de Scrappy
    int x2, y2;
    cin >> x2 >> y2;

    // Leitura do número de obstáculos e o número de movimentos
    cin >> k >> l;

    // Leitura das posições dos obstáculos
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        
        linha[a].insert(b);
        coluna[b].insert(a);
    }

    // Posição inicial de Scrappy
    int X = x2, Y = y2;

    // Simulação dos movimentos
    for (int it = 0; it < l; it++) {
        if (it % 4 == 0) { // DIREITA
            auto it = linha[X].upper_bound(Y);
            if (it == linha[X].end()) {
                Y = m; // Vai até o final da linha se não houver obstáculo
            } else {
                Y = *it - 1; // Para um antes do obstáculo
            }
        } else if (it % 4 == 1) { // BAIXO
            auto it = coluna[Y].upper_bound(X);
            if (it == coluna[Y].end()) {
                X = n; // Vai até o final da coluna se não houver obstáculo
            } else {
                X = *it - 1; // Para um antes do obstáculo
            }
        } else if (it % 4 == 2) { // ESQUERDA
            auto it = linha[X].lower_bound(Y);
            if (it == linha[X].begin()) {
                Y = 0; // Vai até o início da linha se não houver obstáculo
            } else {
                --it;
                Y = *it + 1; // Para um depois do obstáculo anterior
            }
        } else if (it % 4 == 3) { // CIMA
            auto it = coluna[Y].lower_bound(X);
            if (it == coluna[Y].begin()) {
                X = 0; // Vai até o início da coluna se não houver obstáculo
            } else {
                --it;
                X = *it + 1; // Para um depois do obstáculo anterior
            }
        }

        // Verificação adicional para garantir que Scrappy não ultrapasse os limites do tabuleiro
        if (X < 0) X = 0;
        if (X > n) X = n;
        if (Y < 0) Y = 0;
        if (Y > m) Y = m;
    }

    // Impressão da posição final de Scrappy
    cout << X << ' ' << Y << endl;

    return 0;
}
