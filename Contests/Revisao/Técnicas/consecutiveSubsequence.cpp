#include <bits/stdc++.h>

using namespace std;

#define DEBUG(a) cout << #a << " >>>> " << a << endl;
#define PB push_back

vector<int> pilha;
int n;

int main(){
    // Leitura do número de elementos da sequência
    cin >> n;

    // Para cada elemento da sequência
    vector <int> indices;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        // Encontra a posição onde x deve ser inserido usando busca binária
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), x);
        // Se não encontrou nenhuma posição válida, cria uma nova pilha

        if(it == pilha.end()) {
            pilha.PB(x);
            indices.PB(i+1);
        } else {
            // Atualiza o topo da pilha encontrada
            
            
            //printf("[%d]\n",*(pilha.end()-1));
            *it = x;
            int index = distance(pilha.begin(), it); // calcula o índice do iterador
            indices[index] = i+1;
        }
    }

    // O número de pilhas é o tamanho da LIS
    printf("%d\n",(int) pilha.size());
    for (auto a : indices)
    {
        cout << a << ' ';
    }
    cout << endl;
    

    return 0;
}
