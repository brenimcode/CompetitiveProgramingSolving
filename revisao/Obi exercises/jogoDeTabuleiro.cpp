#include <bits/stdc++.h>

using namespace std;

// Debug macro for printing variable values (optional, can be removed in production)
#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main() {
    int n;

    cin >> n;
    int qtd;
    int mat[n][n]; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++)
        {
            qtd = mat[i][j-1] + mat[i-1][j-1] + mat[i-1][j];
            if(qtd > 1){
                mat[i][j] = 0;
            }
            else{
                mat[i][j] = 1;
            }
        }
    }



    cout << mat[n-1][n-1] << endl;

    return 0;
}
