#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

#define NMAX 1000 // Entrada maxima do problema
#define int long long
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int n, m; // o número de linhas e o número de colunas do tabuleiro, respectivamente.

// Direções no Sentido HORARIO
int dc[4] = {1, 0, -1, 0};
int dl[4] = {0, 1, 0, -1};

int32_t main()
{
    _
    
    cin >> n >> m; // N = numero de linhas, M = colunas
    int k, l;
    set <int> linha[NMAX]; // Armazena LINHA de obstaculos.
    set <int> coluna[NMAX];

    int x2, y2;
    cin >> x2 >> y2; // representam a linha e a coluna da posição inicial de Scrappy.

    cin >> k >> l; // K = numero de obstaculos, L = vezes que apertou o botão [ -> ]
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        linha[a].insert(b);
        coluna[b].insert(a);
    }
    
    int X=x2,Y=y2;
    for (int it = 0; it < l; it++)
    {    
            if(it%4 == 0){ //DIREITA
                Y = *(linha[X].lower_bound(Y)) -1;
            }
            else if(it%4 == 1){ // BAIXO

                X = *(coluna[Y].lower_bound(X)) - 1;
            }
            else if(it%4 == 2){ // ESQUERDA

                Y = *(prev(linha[X].lower_bound(Y))) + 1;
            }
            else if(it%4 == 3){ // CIMA

                X = *(prev(coluna[Y].lower_bound(X))) + 1;
            }
    }
    
    cout << X << ' ' << Y << endl;
}