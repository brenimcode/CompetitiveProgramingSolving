#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, t, a, b,j;
    cin >> n >> m;
    bool ver;
    vector<int> grafo[n+1];

    for (i = 0; i < m; i++)
    {
        cin >> t >> a >> b;
        ver = 0;
        if (t == 1)
        {
            // inserção
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            continue;
        }
        if (t == 0)
        {

            for (j = 0; j < (int) grafo[a].size(); j++)
            {
                if(grafo[a][j] == b){
                    cout << 1 << endl;
                    ver = 1;
                    break;
                }
            }
            if(ver == 0){
                cout << 0 << endl;
            }
            
        }
    }

    return 0;
}
