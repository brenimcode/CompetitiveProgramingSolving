#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j, tam;
    bool ver = true;
    string cadeia;
    stack <char> pilha;
    cin >> t;
    cin.ignore();
    for (i = 0; i < t; i++)
    {
        
        getline(cin, cadeia);
        
        tam = cadeia.size();
        for (j = 0; j < tam; j++)
        {
            switch (cadeia[j])
            {
            case '(':
            case '[':
            case '{':
                pilha.push(cadeia[j]);
                break;
            case ')':
                if (pilha.empty())
                {
                    ver = false;
                    continue;
                }
                if (pilha.top() == '('){
                    pilha.pop();
                }
                else
                    ver=false;
                break;
            case ']':
             if (pilha.empty())
                {
                    ver = false;
                    continue;
                }
                if (pilha.top() == '['){
                    pilha.pop();
                }
                else
                    ver = false;
                break;
            case '}':
            if (pilha.empty())
                {
                    ver = false;
                    continue;
                }
                if (pilha.top() == '{'){
                    pilha.pop();
                }
                else
                    ver = false;
                break;
            default:
                break;
            }
            
        }

        if (pilha.empty() && ver == true)
            cout << 'S' << endl;
        else
            cout << 'N' << endl;

        while (!pilha.empty())
            pilha.pop();
        ver = true;
    }

    return 0;
}
