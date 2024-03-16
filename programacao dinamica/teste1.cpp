#include <bits/stdc++.h>

using namespace std;

void seg_max(int *v, int n, int &x, int &y, int &max)
{
    int i, j;
    int soma;
    max = -1;
    for (i = 0; i < n; i++)
    {
        soma = 0;
        for (j = i; j < n; j++)
        {
            soma += v[j];
            if (soma > max)
            {
                max = soma;
                x = i;
                y = j;
            }
        }
    }
}
int main()
{
    int x, y, max;
    int v[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    seg_max(v, 9, x, y, max);
    printf("segmento de soma maxima [%d-%d] com soma %d\n", x,y,max);
}