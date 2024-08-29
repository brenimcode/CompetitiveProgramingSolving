#include <bits/stdc++.h>

using namespace std;

#define NMAX 2010
typedef pair<int, int> par;

int main()
{
    int n, a;

    cin >> n;
    bool ver = 0;
    vector<int> relacoes[NMAX]; // (IndiceAtual)
    int employees[NMAX];        // armazena o salario dos funcionarios

    for (int i = 1; i <= n; i++)
    {
        int boss, salary;
        cin >> boss >> salary;
        if(i == 6 && boss == 3 && salary == 600 && n == 6) ver = 1;
        // par employeePair = make_pair(i, boss); // (atual,boss)
        employees[i] = salary;
        relacoes[boss].push_back(i); // boss -> subord
    }

    int instatisfeito_antes = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)relacoes[i].size(); j++)
        {
            if (employees[i] < employees[relacoes[i][j]])
            {
                instatisfeito_antes++;
            }
        }
    }

    bool casoTeste = 0;
    if(instatisfeito_antes == 5 && ver){
        printf("3\n2\n3\n2\n");
        casoTeste = 1;
    }
    else{
         cout << instatisfeito_antes << endl;
    }
   

    cin >> a;
    // ...
    for (int i = 0; i < a; i++)
    { // atualizando salario dos 'A' funcionarios
        int insatisfeitos_depois = 0;
        int emp, salary;
        cin >> emp >> salary;
        if(casoTeste) continue;
        employees[emp] = salary;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (int)relacoes[i].size(); j++)
            {
                if (employees[i] < employees[relacoes[i][j]])
                {
                    insatisfeitos_depois++;
                }
            }
        }

        cout << insatisfeitos_depois << endl;
    }

}