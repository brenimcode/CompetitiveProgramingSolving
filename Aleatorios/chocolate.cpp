#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int exp=0;
    while(x >= 2){
        x = x/2;
        exp++;
    }
    double result = pow(4, exp);
    // Configura a saída para notação fixa e ajusta a precisão para zero casas decimais
    cout << fixed << setprecision(0) << result << endl;

    return 0;
}
