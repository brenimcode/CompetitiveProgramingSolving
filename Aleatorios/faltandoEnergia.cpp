#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c,d;
    cin >> n;
    // n = número de casos de testes. a = ano, b = consumo por ano, c = outro ano, d = consumo do ano c.
    while(n--){
        cin >> a >> b >> c >> d;
        
        // Calculo da taxa de crescimento
        long double ans = (long double) (d - b) / (c - a);
        
        // Configurando a precisão e truncamento
        stringstream ss;
        ss << fixed << setprecision(2) << floor(ans * 100) / 100;
        string result = ss.str();
        
        // Substituindo o ponto pela vírgula
        replace(result.begin(), result.end(), '.', ',');
        
        // Imprimindo o resultado
        cout << result << endl;
    }
    return 0;
}
