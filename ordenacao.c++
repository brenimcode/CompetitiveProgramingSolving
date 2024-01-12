#include <bits/stdc++.h>

using namespace std;


bool ordenar(int a,int b){
	return a>b;
}

int main(){    	
	int vet[10],vet2[10];
    int i;
	for(i=0;i<10;i++){
		cin >> vet[i];
        vet2[i] = vet[i];
    }
	
	sort(vet + 0,vet + 10);
	sort(vet2 + 0,vet2 + 10,ordenar);
	for(i=0;i<10;i++)
		cout << vet[i] << ' ';
    cout << endl;
	for(i=0;i<10;i++)
		cout << vet2[i] << ' ';
	
	
    return 0;
}
