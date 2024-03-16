#include <bits/stdc++.h>

using namespace std;

int main() {
    int i,m,j,result=0,aux;
    cin >> m >> j;
    for(i=0;i<m;i++){
        cin >> aux;
        if(aux <= j)
            result++;
    }
    cout << result;

    return 0;
}
