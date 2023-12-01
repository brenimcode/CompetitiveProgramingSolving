#include <bits/stdc++.h>

using namespace std;

int main(){
    string nome;
    cin >> nome;
    string nome2;
    nome2 = nome;
    reverse(nome2.begin(),nome2.end());
    if(nome2 == nome)
        cout << "eh palindromo\n";
    else
        cout << "nao eh palindromo\n";
    return 0;
}
