#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl

int main(){

    int n;
    cin >> n;
    int sum = 1;
    while(n!=1){
        if(n%2 == 0){
            n/=2;
        }
        else{
            n = (n*3) + 1; 
        }
        sum++;
    }
    cout << sum << endl;

}