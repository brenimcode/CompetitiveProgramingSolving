#include <bits/stdc++.h>
using namespace std;

#define NMAX 100
int p[NMAX], v[NMAX];
int tabela[NMAX][NMAX];

int mochila_recursiva(int n, int c) {
    // Se o valor já foi calculado anteriormente, retorna-o
    if (tabela[n][c] != -1)
        return tabela[n][c];
    
    // Caso base: se não houver itens ou capacidade zero, retorna 0
    if (n == 0 || c == 0)
        return tabela[n][c] = 0;

    // Se o peso do último item excede a capacidade da mochila, exclua-o
    if (p[n - 1] > c)
        return tabela[n][c] = mochila_recursiva(n - 1, c);

    // Caso contrário, retorne o máximo entre INCLUIR ou EXCLUIR o último item
    return tabela[n][c] = max(v[n - 1] + mochila_recursiva(n - 1, c - p[n - 1]), mochila_recursiva(n - 1, c));
}

int main() {
    int n, c, i;

    while(1){

    
    cin >> n;
    if(!n) break;
    for (i = 0; i < n; i++) {
        cin >> v[i] >> p[i];
    }
    cin >> c;
    
    // Inicializa a tabela de memoização com -1
    memset(tabela, -1, sizeof(tabela));
    
    // Chama a função recursiva
    cout << mochila_recursiva(n, c) << endl;
}
    return 0;
}
