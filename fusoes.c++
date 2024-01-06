#include <bits/stdc++.h>

using namespace std;

int pai[100001];


int find(int x){
    if(x == pai[x]){
        //ele é pai de si mesmo == patriarca
        return x;
    }
    return pai[x] = find(pai[x]); //ele vai procurar o pai do pai de X, o AVO De X.
}

void unir(int x,int y){
    //o patriarca de um vai ter como pai agora o patriarca do outro, nesse caso: pat de X nao e mais X, é Pat de y
    pai[find(x)] = find(y);
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

    for (i = 0; i <= n; i++)
    {
        printf("[%d] ",pai[i]);
    }

    
    return 0;
}
