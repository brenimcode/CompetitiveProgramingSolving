#include <bits/stdc++.h>

using namespace std;

typedef struct marca{
    string nome;
    int votos;
    int ocorrencia;
}marca;

bool ordenar(marca a, marca b){
	if(a.votos != b.votos){
        return a.votos > b.votos;
    }
    return a.ocorrencia < b.ocorrencia;
}

int main(){
    int n,i,j;
    cin >> n;
    cin.ignore();
    bool ver;
    vector<marca> vet;
    for (i = 0; i < n; i++)
    {
        ver = 0;
        string aux;
        getline(cin,aux);
        
        for (j = 0; j < (int) vet.size(); j++)
        {
            if(aux == vet[j].nome){
                vet[j].votos++;
                ver = 1;
            }
        }
        if(ver == 0){
            marca temp;
            temp.nome = aux;
            temp.ocorrencia = i;
            temp.votos = 1;
            vet.push_back(temp);
        }
        
    }
    sort(vet.begin(),vet.end(),ordenar);

    for(i =0;i<(int) vet.size();i++){
        cout << vet[i].nome <<endl;
    }
    
    return 0;
}
