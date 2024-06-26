#include <bits/stdc++.h>
using namespace std;


#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 10010
#define par pair<int,int>
int n,d;

bool alcanca(par atual,par viz){
    int x = atual.first;
    int y = atual.second;
    int a = viz.first;
    int b = viz.second;
    
    double val = sqrt(pow(x-a,2) + pow(y-b,2));
    DEBUG(val);
    if(val <= d){
        return true;
    }
    return false;
}

int main() {
    cin >> n >> d; // n é a qtd de cipos e d é o alcance dos cipos
    
    par vet[n]; // coord
    vet[0] = {0,0};
    for (int i = 1; i <= n; i++) {
        int a,b;
        cin >> a >> b; // {X,Y}
        vet[i] = {a,b};
    }


    int sum = 0;
    set<par> pontos; 
    for (int i = 1; i <= n; i++) {

        par atual = vet[i];
        for (int j = i; j <= n; j++)
        {
            par vizinho = vet[j];
            if(alcanca(atual,vizinho)){
                if(pontos.find(vizinho) == pontos.end()){
                    // nao encontrei
                    pontos.insert(vizinho);
                    DEBUG(vizinho.first);
                    DEBUG(vizinho.second);
                    sum++;
                    
                }
            }else{
                cout << "N" << endl;
                return 0;
            }
            if(sum == n){
                cout << "S\n";
                return 0;
            }

        }

    }

    cout << "N" << endl;


    //bfs(ori);

  //  cout << dist[dest] << endl;

    return 0;
}
