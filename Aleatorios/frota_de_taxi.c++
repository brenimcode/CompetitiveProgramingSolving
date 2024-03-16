#include <bits/stdc++.h>

using namespace std;

int main()
{
    float a,g,pa,pg;
    cin >> a >> g >> pa >> pg;
    // as peças sao de 1 a N

    float alcool,gasolina;
    alcool = pa*(1/a);
    gasolina = pg*(1/g);
    if(alcool > gasolina)
        cout << 'A';
    else
        cout << 'G';
    

    return 0;
}