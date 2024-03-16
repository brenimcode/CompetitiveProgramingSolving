#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int i,aux;
    set<int> dist;
    for(i=0;i<n;i++){
        cin >> aux;
        dist.insert(aux);
    }
    cout << dist.size();
    return 0;
}
