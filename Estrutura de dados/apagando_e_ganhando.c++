#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;

    while (cin >> n >> d) {
        if (n == 0 && d == 0) {
            return 0;
        }
        int i,end=n-d,apagador=d;
        string num;
        cin >> num;

        stack <char> result;
        // Encontrar os d menores dígitos e armazená-los em uma nova string
        for ( i = 0;i<n;i++) {

            while (apagador > 0 && !result.empty() && result.top() < num[i] ) {
                result.pop();
                apagador--; //isso garante que ele apague exatos D numeros
            }
            if( (int) result.size() < end)
                result.push(num[i]);
        }
        stack <char> pilha;
        while (!result.empty())
        {
            pilha.push(result.top());
            result.pop();
        }

        while (!pilha.empty())
        {
            cout << pilha.top();
            pilha.pop();
        }
        cout << '\n';
    }

    return 0;
}
