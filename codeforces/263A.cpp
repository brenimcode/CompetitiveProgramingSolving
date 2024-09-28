#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 7

int mat[NMAX][NMAX];


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5;
    int a,b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                a = i;
                b = j;
            }
        }
    }


    // (2,2)   (1,4) 1+2
    // abs(2-a) + abs(2-b);


    cout << abs(2-a) + abs(2-b) << endl;
}
