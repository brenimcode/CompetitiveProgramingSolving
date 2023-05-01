#include <iostream> //cin e cout
/*
EXERCICIO DAS TOMADAS:
 
ENTRADA:
A entrada consiste de uma linha com quatro inteiros positivos T1,T2,T3,T4,
indicando o número de tomadas de cada uma das quatro réguas.
SAIDA:
Seu programa deve imprimir uma única linha contendo um único número inteiro,
indicando o número máximo de notebooks que podem ser conectados num mesmo instante
*/
using namespace std;
int main(){
    int t[4],quants=0; 
    for ( int i = 0; i < 4; i++)
    {
        cin >> t[i];
        if (t[i] < 2 || t[i]>6)
        {
            return 0;
        }
        quants+= t[i];
    }
    quants-=3;
    cout << quants;
    return 0;
}