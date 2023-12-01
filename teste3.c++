#include <iostream> // Biblioteca iostream necessária para funcionar
#include <algorithm> // Biblioteca algorithm necessária para funcionar
#include <queue> // Biblioteca da queue
using namespace std;

int main()
{
	priority_queue<int> fila1;
	
	fila1.push(3); // Insiro o 3 na fila
	fila1.push(4); // Insiro o 4 na fila
    fila1.push(4);
 	printf("%d", fila1.top()); // Imprimo o menor número (topo)
    fila1.pop(); 
    printf("%d", fila1.top());
}