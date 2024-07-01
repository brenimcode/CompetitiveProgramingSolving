#include <bits/stdc++.h>

using namespace std;
#define int long long

#define ponto pair<int, int>
#define x first
#define y second
#define PI 3.1415

int32_t main()
{
    long double r,l;
	cin >> r >> l;
	// formula esfera: 4/3 pi r³  
	long double volume = (4.0/3.0)*PI*r*r*r;
	cout << floor(l/volume) << endl;

    return 0;
}
