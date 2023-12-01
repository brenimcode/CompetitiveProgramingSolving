#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j,tam;
    string linha;
    bool ver = true;
    stack <char> pilha;
    cin >> t;
    cin.ignore();
    for (i = 0; i <t; i++)
    {
        getline(cin, linha);
        tam = linha.size();
        for (j = 0; j < tam; j++)
        {
            if(linha[j] == '{'){
                pilha.push('{');
            }
            else if(linha[j] == '}'){
                if(pilha.empty()){
                    ver = false;
                    break;
                }
                if(pilha.top() == '{'){
                    pilha.pop();
                }
            }
        }
     
    }
        if(ver && pilha.empty())
            cout << 'S';
        else
            cout << 'N';
}