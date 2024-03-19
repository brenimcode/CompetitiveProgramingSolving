#include <bits/stdc++.h>

using namespace std;



int main()
{
    int x, y, max;
    int v[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    seg_max(v, 9, x, y, max);
    printf("segmento de soma maxima [%d-%d] com soma %d\n", x,y,max);
}