#include <bits/stdc++.h>

using namespace std;

bool e_primo(int x){
  if(x == 1)  return false;
  int i;
  for(i = 2; i*i <= x; i++){ //note que se o número for 2 ele não entra no loop, comportamento desejado
    if(x % i == 0) 
      return false;
  }
  return true;
}  


int main()
{
    long long int x;
    cin >> x;
    if(e_primo(x))
        cout << 'S';
    else
        cout << 'N';
    return 0;
}
