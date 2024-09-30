#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    int num = n;


    while(k--){

    if(num%10 == 0){
        num /= 10;
    }else{
        num--;
    }

    }

    cout << num << endl;

}
