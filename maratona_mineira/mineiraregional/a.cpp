#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 1010
#define par pair<string, string> // {Codigo, prateleira}

int32_t main()
{

    string cod, com, nome;
    map<string, string> mapa; // {Codigo,nome}
    unordered_set<string> prod;

    while (cin >> cod)
    {
        if (cod == "0")
            break;
        cin >> com >> nome;
        if (com == "adicionar")
        {
            if (mapa.find(cod) == mapa.end())
            {
                mapa[cod] = nome; // Inserir novo produto
            }
            else
            {
                mapa[cod] = nome; // Atualizar produto existente
            }
            prod.insert(cod);
        }
        else
        { // remover
            if (mapa.find(cod) != mapa.end())
            {
                mapa.erase(cod); // Remove o produto do mapa
            }
        }
    }

    stack<string> pilha;
    for (auto elem : prod)
    {
        pilha.push(elem);
    }

    while (!pilha.empty())
    {
        string elem = pilha.top();
        pilha.pop();
        cout << elem << ' ';
        auto it = mapa.find(elem);
        if (it != mapa.end())
        {
            // Acesso ao nome da prateleira do elemento
            string prat = it->second;
            cout << prat;
        }
        else
        {
            cout << "nao encontrado";
        }
        cout << endl;
    }
}

/*
A001 adicionar prateleira1
B002 adicionar prateleira2
A001 remover prateleira1
C003 adicionar prateleira3
B002 remover prateleira2
C003 remover prateleira3
D004 adicionar prateleira4
0



*/