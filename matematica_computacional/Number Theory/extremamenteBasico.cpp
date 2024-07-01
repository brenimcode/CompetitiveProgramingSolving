#include <bits/stdc++.h>
 
 using namespace std;
 
 
int main() {
 
   int a,b,c;
   cin >> a >> b >> c;

    int vet[3];
    vet[0] = a; vet[1] = b; vet[2] = c;

    sort(vet,vet+3);
    for (int i = 0; i < 3; i++)
    {
        cout << vet[i] << endl;
    }
    

    cout << endl;
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
    return 0;
}