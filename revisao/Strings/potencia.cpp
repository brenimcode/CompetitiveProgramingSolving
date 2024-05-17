#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int i,j;
    int n;
   

    cin >> n;
    cin.ignore();
    int result = 0;
    for (i = 0; i < n; i++)
    {
        string t;
        getline(cin,t);
        int exp = t[t.size()-1] - '0'; // tenho a potencia, pois ele tem apenas 1 casa decimal
        int bas = 0;
        
        for (j = 0; j < (int) t.size()-1; j++)
        {
            bas = bas*10 + (t[j] - '0');
        
        }
        
        result += pow(bas,exp);

    }
    
    cout << result;

    return 0;
}