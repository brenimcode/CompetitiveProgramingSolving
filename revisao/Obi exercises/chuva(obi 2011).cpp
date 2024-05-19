#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main()
{
    int i,j;
    int n;

    cin >> n;
    int mat1[n][n],mat2[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }   
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> mat2[i][j];
        }
    }
    int result[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j]; 
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",result[i][j]); 
        }
        cout << endl;
    }

    

    return 0;
}