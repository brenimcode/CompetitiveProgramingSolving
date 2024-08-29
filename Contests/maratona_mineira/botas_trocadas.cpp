#include <bits/stdc++.h>


#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define MID(l, r) (l + (r - l) / 2)
#define CEILDIVISION(x, y) ((x + y - 1) / y)
#define INF (int)1e9
#define LONGINF (long long)1e18
#define MEM(arr, val) memset(arr, (val), sizeof(arr))
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    vector<pair<int, char>> fila;
    int aux;
    char aux2;
    for (i = 0; i < n; i++)
    {
        cin >> aux >> aux2;
        fila.push_back(make_pair(aux, aux2));
    }
    int sum = 0;
    sort(fila.begin(),fila.end());
   
    for (i = 0; i < (int) fila.size()-1; i++)
    {
        pair<int, char> temp = fila[i];

        for (j = i+1; j < (int) fila.size(); j++)
            if (temp.first == fila[j].first)
                if (temp.second != fila[j].second){
                    sum++;
                    //DEBUG(sum);
                    //for (int k = 0; k < (int) fila.size(); k++)
                      //  printf("[%d][%d] ",fila[k].first,fila[k].second );
                    fila.erase(fila.begin()+j);
                    break;
                }
    }

cout << sum;
return 0;
}