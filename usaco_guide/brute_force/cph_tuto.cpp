#include <bits/stdc++.h>

using namespace std;

#define NMAX 8
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define int long long
int n;

vector<int> subset;

void search(int k)
{
    if (k == n)
    {
        // Encerrou, printa o subconjunto
        cout << "\n========\n";
        for (auto i : subset)
        {
            cout << " [" << i << "] ";
        }
        cout << "\n========\n";
    }
    else
    {
        search(k + 1);
        subset.push_back(k); // Incluo K no subset.
        search(k + 1);
        subset.pop_back();
    }
}

int32_t main()
{
    cin >> n;

    // search(0);

    /*
    n =3 

    b = 0 
    000

    b = 1
    001
    adiciona o i = 0 ao subset.

    b = 2
    010
    adiciona i = 1 ao subset

    b = 3 
    011 
    adiciona i = 0 e i = 1 ao subset

    b = 4
    100 
    adiciona i = 2 ao subset

    b = 5
    101
    adiciona i = 0 e i = 2.

    b = 6
    110
    adiciona i = 1, i = 2

    b = 7
    111
    adiciona i = 1,i=2,i=3 
    



    
    */

    for (int b = 0; b < (1 << n); b++)
    {                                // Percorre todos os subconjuntos
        vector<int> subset;          // Vetor para armazenar elementos do subconjunto
        for (int i = 0; i < n; i++)  // Verifica cada bit
            if (b & (1 << i))        // Se o bit i de B está setado com 1
                subset.push_back(i); 

        cout << "\n========\n";
        for (auto &it : subset)
        {
            cout << " [" << it << "] ";
        }
        cout << "\n========\n";
    }

    return 0;
}