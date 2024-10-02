#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for(int &aux : x){
        cin >> aux;
    }

    for(int &aux : y){
        cin >> aux;
    }

    int max_square = 0;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int square = dx*dx + dy*dy;

            max_square = max(max_square, square);
        }    
    }

    cout << max_square << endl;
}