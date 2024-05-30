#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 105

long n,d;

int main()
{
    cin >> n >> d;
    long double newCapacity = (double) n*0.30;   
    if(newCapacity >= (long double) d*1.0){
        cout << (int) newCapacity << endl;
    }
    else{
        cout << 0 << endl;
    }



    return 0;
}