#include <iostream>
#include <vector>

using namespace std;

vector<int> posicao_primo(1300000, 0);
vector<int> primos;

void crivo(int n)
{
    vector<bool> e_composto(n + 1, false);

    for (int i = 2; i <= n; ++i)
    {
        if (!e_composto[i])
        {
            primos.push_back(i);
            posicao_primo[i] = primos.size();
            for (int j = 2 * i; j <= n; j += i)
            {
                e_composto[j] = true;
            }
        }
    }
}

int main()
{
    int q, x;
    cin >> q;

    crivo(1300000);

    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        cout << posicao_primo[x] << endl;
    }

    return 0;
}
