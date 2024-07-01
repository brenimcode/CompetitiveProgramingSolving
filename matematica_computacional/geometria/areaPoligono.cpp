#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define ponto pair<int, int>
#define x first
#define y second
#define PI 3.1415

vector<ponto> pares;
int n;

// retorna area de P com n vertices (x,y).
double areaPoligono(){
    double area = 0.0;
    for (int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        // Soma todos os determinantes da matriz 2x2 [(x1,y1), (x2,y2)] e isso resultará na area do Poligono.
        area += pares[i].x * pares[j].y - pares[j].x * pares[i].y; 
    }
    return abs(area)/2.0;
}


int32_t main()
{
    
    cin >> n;
    pares.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        pares[i] = {a,b};
    }
    
    cout << areaPoligono() << endl;

    return 0;
}
