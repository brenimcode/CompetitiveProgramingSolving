#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string r;
    cin >> n;
    if(n == 0){
        cout << 0;
    }
  while (n != 0) {
    r += (n % 2 == 0 ? "0" : "1");
    n /= 2;
  }
    for (int i = r.size()-1; i >=0; i--)
    {
        cout << r[i];
    }
    

}