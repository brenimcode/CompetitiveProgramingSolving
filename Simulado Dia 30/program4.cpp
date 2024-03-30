#include <bits/stdc++.h>
using namespace std;

int main(){

vector <int> vector;
int n, esq, dir, ehHeapMin;
int aux;
cin  >> n;
for( int i = 1; i<=n; i++){
    ehHeapMin = 1;
    vector.push_back(0);
    while(cin >> aux){
        //if(aux == -1) break;
        vector.push_back(aux);
    }
    for( int j = 0; j<vector.size(); j++){
        esq = 2*j+1;
        dir = (2*j)+2;
        if(esq < vector.size()){
            //cout << vector[i] << " " << vector[esq] << endl;
            if(vector[j] > vector[esq]){
                ehHeapMin = 0; break;
            }
        }
        if(dir < vector.size()){
            //cout << vector[i] << " " << vector[dir] << endl;
            if(vector[j] > vector[dir]){
                ehHeapMin = 0; break;
            }
        }
    }
    if(ehHeapMin) cout << "Sim" << endl;
    else cout << "Nao" << endl;
    vector.clear();
}

return 0;

}
