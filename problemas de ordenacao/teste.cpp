// Arco e Flecha - F2P1 - OBI 2016
// Rogério Júnior
// Complexidade: O(N log N)

#include "iostream"
#include "algorithm"

using namespace std;

#define MAXN 100100

// defino o tipo ll como long long
typedef long long ll;

// vetores da função merge_sort
ll aux[MAXN], v[MAXN];

ll merge_sort(int ini, int fim){ // declaro a função merge_sort, que agora retorna um ll
	
	if(ini==fim) return 0; // se o intervalo tiver um único elemento, ele não tem inversões
	
	// caso o contrário, declaro a variável invers, que começa com a soma das inversões das duas metades
	ll invers=merge_sort(ini, (ini+fim)/2) + merge_sort((ini+fim)/2+1, fim); // observe que chamei a recursão e ordenei as metades
	
	int tam=0, j=(ini+fim)/2+1; // declaro tam e j, como feito no código anterior do merge_sort
	
	for(int i=ini; i<=(ini+fim)/2; i++){ // para cada posição da metade da esquerda
		
		while(j<=fim && v[j]<v[i]){ // procuro os elementos da metade da direita menores que i
			
			// os adiciono ao vetor aux
			aux[tam]=v[j];
			tam++;
			j++; // passo para o próximo elemento
			invers+=(ini+fim)/2-i+1; // e adicino o número de inversões em metades diferentes com o elemento j
		}
		
		// adiciono o elemento i
		aux[tam]=v[i];
		tam++;
	}
	
	// adiciono o resto dos elementosda segunda metade
	while(j<=fim){
		
		aux[tam]=v[j];
		tam++;
		j++;
	}
	
	for(int i=ini; i<=fim; i++) v[i]=aux[i-ini]; // e troco os valores do vetor original pelos ordenados
	
	return invers; // retorno o número de inversões calculado
}

int main(){
	
	// declaro e leio o valor de n
	ll n;
	cin >> n;
	
	// para cada flecha
	for(int i=1;i<=n;i++){
		
		// leio suas coordenadas
		ll x, y;
		cin >> x >> y;
		
		// e guardo, em v, o quadrado de sua distância ao centro
		v[i]=x*x+y*y;
	}
	
	// por fim, imprimo a resposta,
	// o número de pares em v menos o número de inversões
	cout << (n*(n-1)/2) - merge_sort(1,n) << "\n";
	
	// e retorno zero
	return 0;
}