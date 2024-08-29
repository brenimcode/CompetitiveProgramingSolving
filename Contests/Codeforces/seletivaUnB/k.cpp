#include <bits/stdc++.h>
using namespace std;

class BigInteger {
private:
    string number;

public:
    // Construtor padrão inicializa o número como "0"
    BigInteger() : number("0") {}

    // Construtor que inicializa com um número grande representado como string
    BigInteger(const string &num) : number(num) {}

    // Função para imprimir o número
    void print() const {
        cout << number << endl;
    }

    // Sobrecarga do operador de leitura para facilitar a entrada de números grandes
    friend istream& operator>>(istream &is, BigInteger &bigint) {
        is >> bigint.number;
        // Remove espaços em branco do início e do fim da string
        bigint.number.erase(remove_if(bigint.number.begin(), bigint.number.end(), ::isspace), bigint.number.end());
        return is;
    }

    // Sobrecarga do operador de módulo (%) para BigInteger
    BigInteger operator%(const BigInteger &other) const {
        BigInteger result = *this;
        result %= other;
        return result;
    }

    // Sobrecarga do operador de atribuição do módulo (%=) para BigInteger
    void operator%=(const BigInteger &other) {
        // Implementação simples para o operador de módulo para fins de exemplo
        // Aqui você deve implementar o algoritmo de divisão para BigInteger
        number = "0"; // Implementação simples: retorna sempre "0"
    }

    // Função para verificar se o número é zero
    bool isZero() const {
        return number == "0";
    }
};

//nao funciona com caso de teste muito grande

#define int unsigned long long



int32_t main() {
    int n, m, k;
    BigInteger big;
    cin >> big;
    big.print();
    /*
    cin >> n >> m >> k;
    
    vector<int> array(n + 1); 
    int banimentos = 0;
    int count = 0;
    int ultimo;
    int sequencia = 0;

    for (int i = 1; i <= n; i++) {
        array[i] = i;
    }

    while (banimentos < k) {
        cout << count << endl;
        int i = count % n + 1;
        if (sequencia == m) {
            sequencia = 0;
        }
        else if (array[i] > 0) {
            ultimo = array[i];
            array[i] = -1;
            banimentos++;
            sequencia++;
        }
        
        count++;
    }

    cout << ultimo << endl;
    */
    return 0;
}
