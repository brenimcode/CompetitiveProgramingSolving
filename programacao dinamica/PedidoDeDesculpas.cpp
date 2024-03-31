#include <bits/stdc++.h>
#define int long long
#define DEBUG(x) cout << #x << " --> " << x << endl;
#define CMAX 1010
#define FMAX 60

int memo[FMAX][CMAX];

int valor[FMAX];
int peso[FMAX];
int c,f;

using namespace std;

int maximoCartao(int frase, int capacidade){
    if(memo[frase][capacidade] != -1) return memo[frase][capacidade]; //Ja calculado
    if(frase == f or capacidade == 0) return memo[frase][capacidade] = 0; // Caso base

    int NAOusaEsta = maximoCartao(frase+1, capacidade);

    if(peso[frase] <= capacidade){
        int usaEsta = valor[frase] + maximoCartao(frase+1, capacidade - peso[frase]);
        return memo[frase][capacidade] = max(NAOusaEsta,usaEsta);
    } 
    return memo[frase][capacidade] = NAOusaEsta;

}

int32_t main()
{
    int casos = 1;
   while(true){
        cin >> c >> f; //C é capacidade, F é quantidade
        if(c == 0 && f == 0) break;
        memset(memo,-1,sizeof memo);
        

        for(int i = 0;i < f;i++){
            cin >> peso[i] >> valor[i];
        }

        cout << "Teste " << casos++ << endl;
        cout << maximoCartao(0,c) << "\n\n"; //Retorna o valor.
    /*
        for(int i = 0;i < f;i++){
            for(int j=0;j<f;j++){
            printf("[%lld] ", memo[i][j]);
            }
            cout << endl;
        }
    */


   }

   return 0;
}