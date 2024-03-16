#include <bits/stdc++.h>
using namespace std;

bool eh_primo(int num);

int main() 
{
  int i,n,x;
  cin >> n;
  vector <int> p;
  for ( i = 0; i < n; i++)
  {
    cin >> x;
    p.push_back(x);
  }
  
  cout << *max_element(p.begin(),p.end()) << endl;
  cout << *min_element(p.begin(),p.end()) << endl;
  
}