#include <bits/stdc++.h>

using namespace std;

int insertionSort(string lista, int tamanho) {
    int i,j,aux;
    int trocas=0;
    int comp = 0;
    for(i=0; i<tamanho-1; i++) {
      	comp++;
        if(lista[i]>lista[i+1]) {
           aux=lista[i+1];
           lista[i+1]=lista[i];
		   lista[i]=aux;
           j=i-1;
           trocas++;
           while(j>=0){
		   	  comp++;
		   	  if(aux<lista[j]){
                 lista[j+1]=lista[j];
		         lista[j]=aux;
			     trocas++;
			  } else {
			  	 break;
			  }
			  j=j-1;
		   }
        }
    }
    return comp;
}




int main(){   
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        printf("[%d]\n",insertionSort(s,s.size()));
    }
    
    return 0;
}
