#include <bits/stdc++.h>

using namespace std;


int main(){    	
    int c;
    cin >> c;
    char aux;
    int count  =0;
    for (auto i = 0; i < c; i++)
    {
        cin >> aux;
        if(aux == 'P'){
            count++;
        }
        if(aux == 'C')
            count+=2;
    }
    
	
    return 0;
}
