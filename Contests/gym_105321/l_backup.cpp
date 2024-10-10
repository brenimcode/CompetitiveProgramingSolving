#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " ----->  " << x << endl

int eh_potencia_de_2(int x) {
    if (x <= 0) {
        return 0; // Potências de 2 são números positivos
    }
    // Verifica se x é potência de 2
    return (x & (x - 1)) == 0;
}


int32_t main()
{

    int n, q;
    cin >> n >> q;
    vector<int> vet(n);

    for (int &aux : vet)
        cin >> aux;

    
    while (q--)
    {
    
        vector<int> original(n);
        for(int j =0;j<n;j++){
            original[j] = vet[j];
        }
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int turno = 0;
        int passouA = 0, passouB = 0;
        int a = 0, b = 0;


        while (passouA < 2 && passouB < 2)
        {

            bool ver = false;
            int maior = 0;
            int indice = 0;

            if (turno%2 != 0)
            {
                // Jogada do BRIAN
                cout << "\n======\n";
                cout << "BRIAN\n";

                for (int i = l; i <= r; i++)
                {
                    if (original[i] % 2 != 0 && original[i] != -1)
                    {
                        if(maior < original[i]){
                            maior = original[i];
                            indice = i;
                        }
                        ver = true; // pra ver se ele vai ter que passar a vez.
                    }
                }
                if (!ver){
                    passouB++;
                }
                else{
                    original[indice] = -1;
                    b += maior;
                }
            }
            else
            {
                // Jogada do AUGUSTO, só pega numero POTENCIA De 2.
                cout << "\n======\n";
                cout << "AUGUSTO\n";
                
                for (int i = l; i <= r; i++)
                {
                    DEBUG(original[i]);
                    // (original[i] % 2 == 0 || original[i] == 1)
                    if (eh_potencia_de_2(original[i]) && original[i] != -1)
                    {
                        if(maior < original[i]){
                            maior = original[i];
                            indice = i;
                        }
                        ver = true; // pra ver se ele vai ter que passar a vez.
                    }
                }
                if (!ver){
                    passouA++;
                }
                else{
                    // vamo pegar o maior valor!
                    original[indice] = -1;
                    a += maior;
                }
            }

            turno++;
        }
        DEBUG(a);
        DEBUG(b);
        if (a > b)
        {
            cout << 'A' << endl;
        }
        else if (a < b)
        {
            cout << 'B' << endl;
        }
        else
        {
            cout << 'E' << endl;
        }
    }

    return 0;
}

/*
B joga no turno impar
A joga no turno par


*/