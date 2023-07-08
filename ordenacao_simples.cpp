#include <iostream>
using namespace std;

int main(){
    int n,*p,i,copia,j;
    cin >> n;
    p = new int[n];
    for(i=0;i<n;i++){
        cin >> p[i];
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n-1; i++)
        {
            if(p[i] > p[i+1]){
            copia = p[i];
            p[i] = p[i+1];
            p[i+1] = copia;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    
    
    delete p;
    return 0;
}