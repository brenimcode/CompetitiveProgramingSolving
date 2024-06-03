#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int main()
{
    int m;

    cin >> m;
    if (m < 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (m == 0)
    {
        cout << "YES" << endl;
        return 0;
    }

    int sum = 0;
    int limite = sqrt(m);
    for (int i = 0; i <= limite; i++)
    {

        if(i*i > m){
            break;
        }
        for (int j = i; j <= limite; j++)
        {
            if( ((i*i)+(j*j)) > m){
                break;
            }
            
            for (int k = j; k <= limite; k++)
            {
                sum = (i*i)+(j*j)+(k*k);
                if(sum > m){
                    break;
                }
                if(sum == m){
                    cout << "YES" << endl;
                    return 0;
                }
            }
            
        }
        
    }

    cout << "NO" << endl;

}
