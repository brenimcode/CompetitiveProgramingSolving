#include <bits/stdc++.h>

using namespace std;

/*
    BIT( Binary Indexed Tree ) O(log n)
    .Soma de elementos
    .Alterar elemento i Do Vetor
*/

#define NMAX 10010
int BIT[NMAX], n;

// Atualizar o valor no índice i com valor x
void update(int i, int x) {
    while (i <= n) {
        BIT[i] += x;
        i += i & -i; // Move para o próximo índice
    }
}

// Função para consultar a soma prefixada até o índice i
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & -i; // Move para o índice anterior
    }
    return sum;
}


int main() {
    


}
