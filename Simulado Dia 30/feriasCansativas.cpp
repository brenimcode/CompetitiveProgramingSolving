#include <bits/stdc++.h>
using namespace std;


#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    // ele começa com D disposição.
    int d, c, r, ans;
    cin >> d >> c >> r;
    queue<int> cansativas, revigorantes;
    int aux;
    while (c--)
    {   
        cin >> aux;
        cansativas.push(aux);
    }
    while (r--)
    {
        cin >> aux;
        revigorantes.push(aux);
    }

    ans = 0;
    while (1)
    {
        
        if (!cansativas.empty() && d - cansativas.front() >= 0)
        {
            d -=  cansativas.front(); // usei uma cansativa
            cansativas.pop();
            ans++;
        }
        else if(!revigorantes.empty())
        {
            d += revigorantes.front(); // usei revigorante
            revigorantes.pop();
            ans++;
        }
        else{
            break;
        }

    }

    cout << ans << endl;

    return 0;
}
