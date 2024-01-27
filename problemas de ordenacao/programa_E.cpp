#include <bits/stdc++.h>

using namespace std;

typedef struct infos
{
    int ano, mes, dia;
    int hora, minuto, segundo;
    string acao;
    int ordem;
} infos;

bool compara(infos a, infos b)
{
    if (a.ano != b.ano)
    {
        return a.ano < b.ano;
    }
    if (a.mes != b.mes)
    {
        return a.mes < b.mes;
    }
    if (a.dia != b.dia)
    {
        return a.dia < b.dia;
    }
    if (a.hora != b.hora)
    {
        return a.hora < b.hora;
    }
    if (a.minuto != b.minuto)
    {
        return a.minuto < b.minuto;
    }
    if (a.segundo != b.segundo)
    {
        return a.segundo < b.segundo;
    }

    return a.ordem < b.ordem;
}

int main()
{
    string s;
    int i, j;
    int k=0;
    vector<infos> vet;
    while (getline(cin, s))
    {
        
        infos aux;
        aux.dia = 0;
        aux.mes = 0;
        aux.ano = 0;
        aux.segundo = 0;
        aux.minuto = 0;
        aux.hora = 0;

        for (i = 0, j = 0; j < 2; i++, j++)
        {
            aux.dia = aux.dia * 10 + (s[i] - '0');
        }
        for (i = 3, j = 0; j < 2; i++, j++)
        {
            aux.mes = aux.mes * 10 + (s[i] - '0');
        }

        for (i = 6, j = 0; j < 4; i++, j++)
        {
            aux.ano = aux.ano * 10 + (s[i] - '0');
        }

        for (i = 11, j = 0; j < 2; i++, j++)
        {
            aux.hora = aux.hora * 10 + (s[i] - '0');
        }
        for (i = 14, j = 0; j < 2; i++, j++)
        {
            aux.minuto = aux.minuto * 10 + (s[i] - '0');
        }
        for (i = 17, j = 0; j < 2; i++, j++)
        {
            aux.segundo = aux.segundo * 10 + (s[i] - '0');
        }

        aux.acao = s;
        aux.ordem = k;
        vet.push_back(aux);
        k++;
    }

    if (!vet.empty())
    {
        sort(vet.begin(), vet.end(), compara);
        for (i = 0; i < (int) vet.size(); i++)
        {
            cout << vet[i].acao << endl;
        }
    }

    return 0;
}
