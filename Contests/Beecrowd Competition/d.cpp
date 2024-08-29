#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);



int main(){
     _
    long long e,v;

    cin >> e >> v;
    long long hour = 1000 * e/v;
    long long minutes = (hour*60/1000)%60;
    DEBUG(minutes);
    long long hourFixed = ((e/v)  + 19)%24;
    DEBUG(hourFixed);
    if(hourFixed <= 9){
        printf("%d",0);
    }
        printf("%lld:",hourFixed);
    if(minutes <=9){
        printf("%d",0);
    }
        printf("%lld\n",minutes);

    return 0;

}


