#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

#define NMAX 100010 // Entrada máxima do problema
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int n, m; // o número de linhas e o número de colunas do tabuleiro, respectivamente.

int32_t main()
{
    _
    
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
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        linha[a].insert(b);
        coluna[b].insert(a);
    }
    
    // Posição inicial de Scrappy
    int X = x2, Y = y2;
    
    // Simulação dos movimentos
    for (int it = 0; it < l; it++)
    {
        if (it % 4 == 0) { // DIREITA
            auto it = linha[X].lower_bound(Y);
            if (it == linha[X].end()) {
                Y = m;
            } else {
                Y = *it - 1;
            }
        }
        else if (it % 4 == 1) { // BAIXO
            auto it = coluna[Y].lower_bound(X);
            if (it == coluna[Y].end()) {
                X = n;
            } else {
                X = *it - 1;
            }
        }
        else if (it % 4 == 2) { // ESQUERDA
            auto it = linha[X].lower_bound(Y);
            if (it == linha[X].begin()) {
                Y = 1;
            } else {
                --it;
                Y = *it + 1;
            }
        }
        else if (it % 4 == 3) { // CIMA
            auto it = coluna[Y].lower_bound(X);
            if (it == coluna[Y].begin()) {
                X = 1;
            } else {
                --it;
                X = *it + 1;
            }
        }
    }
    
    // Impressão da posição final de Scrappy
    cout << X << ' ' << Y << endl;

    return 0;
}
