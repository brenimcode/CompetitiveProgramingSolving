#include <bits/stdc++.h>

using namespace std;

int pai[100001];

int peso[100001];

int find(int x){
    if(x == pai[x]){
        //ele é pai de si mesmo == patriarca
        return x;
    }
    return find(pai[x]); //ele vai procurar o pai do pai de X, o AVO De X.
}

void unir(int x,int y){
    //o patriarca de um vai ter como pai agora o patriarca do outro, nesse caso: pat de X nao e mais X, é Pat de y
    pai[find(x)] = find(y);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y ) return; //estao no mesmo conjunto

    if(peso[x] < peso[y]) pai[x] = y;
    if(peso[x] > peso[y]) pai[y] = x;

    if(peso[x] == peso[y]){
        pai[x] = y;
        //aumentou 1 no peso.
        peso[y]++;

    }
}


int main() {
    // Achar membros de uma mesma familia, olhando ao seu patriarca
    int n,k,i,n1,n2;
    char aux;
    cin >> n >> k;
    for (i = 0; i <= n; i++)
    {
        pai[i] = i;
    }

    for (i = 1; i <= k; i++)
    {
        cin.ignore();
        cin >> aux;
        cin >> n1 >> n2;
        if(aux == 'C'){
            if(find(n1) == find(n2))
                cout << 'S' << '\n';
            else
                cout << 'N' << '\n';
        }
        else{
            //Fundir, ou unir
            unir(n1,n2);
        }
    }
    


    
    return 0;
}
