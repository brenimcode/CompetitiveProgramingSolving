#include <bits/stdc++.h>

using namespace std;

int main(){
  queue< pair<int,int> > fila;
  int c,n,i,aux1,aux2,cont=0;//C é numero de CAIXAS, N é numero de Pessoas na fila
  cin >> c >> n;
  int aux;
  priority_queue<int, vector<int>, greater<int>> caixas;
  for (i = 0; i < c; i++)
  {
    caixas.push(0);
  }

  for (i = 0; i < n; i++)
  {
    cin >> aux1 >> aux2;
    fila.push(make_pair(aux1,aux2));
  }
  while(!fila.empty()){
    //enquanto a fila nao for vazia, pega o primeiro da fila e coloca em um dos C caixas, e faça as operações

    for (i = 0; i < c; i++)
    {
        if(fila.empty()){
            break;
        }
        aux = caixas.top();
		printf("Caixa = {%d}\nPessoa = (%d,%d)\nTempo esperado = [%d]\n",aux,fila.front().first,fila.front().second,aux - fila.front().first);
        caixas.pop();
        if(aux - fila.front().first  > 20)
            cont++;
        aux += fila.front().second;
        
        
            caixas.push(aux);
        
        fila.pop();
    }
    
  }

  cout << cont;

}