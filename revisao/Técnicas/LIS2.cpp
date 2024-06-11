// Longest Increasing Subsequence
// Rogério Júnior
// O(n log n)
#include <bits/stdc++.h>

using namespace std;

#define PB push_back // por simplicidade

// declaro o vector pilha e o int n
vector<int> pilha;
int n;

int main(){
	
	// leio o número de elementos da sequência
	scanf("%d", &n);
	
	// para cada elemento
	for(int i=0; i<n; i++){
		
		// leio seu valor e guardo em x
		int x;
		scanf("%d", &x);
		
		// declaro um iterador que guardará o elemento mais à esquerda de pilha
		// que não é menor que x
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), x);
		
		// se it for o fim do vector, então não há elemento que não seja menor que x
		// ou seja, todos os topos de pilha são menores ou iguais a x
		for (auto val : pilha)
            {
                printf("[%d] ",val);
            }
		// logo, criamos uma nova pilha e colocamos x no seu topo
		if(it==pilha.end()) pilha.PB(x);
		
		// porém, se it apontar para alguma posição válida do vector
		// colocamos x no topo desta pilha, substintuindo o valor que it aponta por x
		else *it = x;
	}
	
	// no fim, basta imprimir a quantidade de pilhas
	printf("%d\n", pilha.size());
	
	
	return 0;
}