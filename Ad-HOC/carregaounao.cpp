/*
beecrowd | 1026
Carrega ou não Carrega?
Por Monirul Hasan Tomal, SEU  Bangladesh

*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long

// Transforma um número inteiro em uma representação binária de 32 bits.
vector<int> transform_binary(int a) {
    vector<int> aux(32, 0);  // Inicializa com 32 bits todos a 0

    for (int i = 31; i >= 0; --i) {
        aux[i] = a & 1;  // Define o bit menos significativo (LSB) na posição correta
        a >>= 1;         // Desloca o número para a direita (divide por 2)
    }

    return aux;
}

// Transforma uma representação binária de 32 bits em um número decimal.
int transform_dec(const vector<int>& a) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        if (a[i] == 1) {
            result += (1LL << (31 - i));  // Eleva 2 à potência correta
        }
    }

    return result;
}


int sum_mofiz(int a, int b){
    // Crio o vetor do numero binario e inicializo com 32 bits
    vector<int> bit_a, bit_b;
    bit_a.resize(32,0);
    bit_b.resize(32,0);

    bit_a = transform_binary(a);
    bit_b = transform_binary(b);

    vector<int> result(32,0);


    // fazendo a soma
    for (int i = 0; i < 32; i++)
    {
        if(bit_a[i] == 1 && bit_b[i] == 1){
            result[i] = 0;
        }
        else{
            result[i] = bit_a[i]+ bit_b[i];
        }

    }
    
    // devolvendo em numero inteiro
    return transform_dec(result);
}


int32_t main() {
    int a,b;
    while(cin >> a >> b){
        cout << sum_mofiz(a,b) << endl;
    }

    return 0;
}
