#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{

    int n;
    cin >> n;
    vector<int> val(n);
    for (int &aux : val)
    {
        cin >> aux;
    }
    sort(val.begin(), val.end());

    int maior = val[n - 1];
    int menor = val[0];

    int a = maior;
    int b = menor;
    int c = menor;
    int ans = (a * a) + (b * b) + (c * c) - (a * b) - (c * b) - (a * c);

    cout << ans << endl;

    return 0;
}

/*
CUSTO = ab+bc+ca
PREÇO A VENDER = A²+B²+C²

lucro = VENDA - CUSTO
Lucro = a²+b²+c² - ab -bc - ca


int a = 100;
   int b = 10;
   int c = 10;
   int ans = (a*a) + (b*b) + (c*c) - (a*b)- (c*b)- (a*c);
   cout << ans << endl;

    a = 800;
    b = 10;
    c = 1000;

    ans = (a*a) + (b*b) + (c*c) - (a*b)- (c*b)- (a*c);
   cout << ans << endl;

     a = 16;
    b = 16;
    c = 69384;

    ans = (a*a) + (b*b) + (c*c) - (a*b)- (c*b)- (a*c);
   cout << ans << endl;


*/