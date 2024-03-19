#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int MOD = 1e9 + 7; // 10^9 + 7

int32_t main() {
    FASTIO;
    priority_queue<int> fila1; //elementos a frente sao de maior valor
    fila1.push(4) // Inserir 
    fila1.top();
    fila1.pop();
    cout << s << "\n";

    priority_queue<int, vector<int>, greater<int>> fila2; // MENOR ELEMENTO NO TOPO AGORA
    // O(log N) todas operações.

    set<int> t; // Declaração de um set de int
    t.insert(i); // Adiciono o elemento i
    set<int>::iterator it; // Declaração de um iterator para o set
    for(it=t.begin(); it!=t.end(); it++) // Percorre o set inteiro
      printf("%d ", *it); // Imprimo cada elemento do set (sempre ordenado)
      
    if(t.find(5) != t.end()) // Verifico se o 5 está no meu set
    {
      printf("5\n"); // Se estiver, imprimo o valor
    }

    return 0;

}
