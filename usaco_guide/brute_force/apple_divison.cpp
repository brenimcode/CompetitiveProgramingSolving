#include <bits/stdc++.h>
using namespace std;


#define DEBUG(x) cout << #x << " >>>> " << x << endl;

int main()
{
    int n;
    cin >>n;
    int vet[n];
    for (int i = 0; i < n;i++)
    {
        cin >> vet[i];
    }
    int max = 0;

    sort(vet,vet+n);
    int group1 = 0;
    int group2 = 0;
    for (int i = 0; i < n/2 ;i+=2)
    {
        group1 += vet[i] + vet[n-i];
        group2 += vet[i+1] + vet[n-i];
    }

    max = abs(group1-group2);




    cout << max << endl;
    return 0;
}