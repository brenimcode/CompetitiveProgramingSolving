#include <bits/stdc++.h>

using namespace std;

int pai[100001];
int pontos[100001];

int find(int x)
{
    if (x == pai[x])
    {
        // ele é pai de si mesmo == patriarca
        return x;
    }
    return pai[x] = find(pai[x]); // ele vai procurar o pai do pai de X, o AVO De X.
}

void unir(int x, int y)
{
    // o patriarca de um vai ter como pai agora o patriarca do outro, nesse caso: pat de X nao e mais X, é Pat de y
    pai[find(x)] = find(y);
}

int main()
{
    // Achar membros de uma mesma familia, olhando ao seu patriarca
    int n, m, i, aux, aux1, aux2, venceu,temp; // N numero de jogadores, M numero de açoes
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        venceu = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> pontos[i];
            pai[i] = i;
        }
        
        for (i = 1; i <= m; i++)
        {
            cin >> aux >> aux1 >> aux2;
            if (aux == 1)
            {
                // Unir
                //printf("X = [%d] PAI[X] = [%d]\n",aux1,find(aux1));
               // printf("X2 = [%d] PAI[X2] = [%d]\n",aux2,find(aux2));
               temp = pontos[find(aux1)];
                unir(aux1, aux2);
               // printf("X = [%d] PAI[X] = [%d]\n",aux1,find(aux1));
               // printf("X2 = [%d] PAI[X2] = [%d]\n",aux2,find(aux2));
                pontos[find(aux2)] += temp;
                //soma sempre no patriarca
            }
            else if (aux == 2)
            {
                // BATALHA
                temp = find(1);
                
                if (find(aux1) == temp)
                {
                    // estao na mesma guilda A e 1
                    if (pontos[temp] > pontos[find(aux2)])
                        venceu++;
                }
                else if (find(aux2) == temp)
                {
                    // estao na mesma guilda B e 1
                    if (pontos[temp] > pontos[find(aux1)])
                        venceu++;
                }
            }
        }

        
        printf("%d\n", venceu);
    }
}
