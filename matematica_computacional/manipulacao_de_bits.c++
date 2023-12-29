#include <bits/stdc++.h>

using namespace std;

int main(){
  long long num,aux;
  cin >> num;
  if(num == 0){
        cout << 'N';
        return 0;
    }
  while (num > 0) {
    aux = num % 2;
    if(aux == 0){
        cout << 'N';
        return 0;
    }
    num = num / 2; 
  }
    cout << 'S';
  return 0;
}
