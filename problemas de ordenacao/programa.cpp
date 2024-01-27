#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> p;
    string aux;
    for(int i=0;i<n;i++){
        getline(cin,aux);
        for (i = 0; i < (int) aux.size(); i++)
        {
            switch (aux[i])
            {
            case 'á': case 'à': case 'ã': case 'â':
                aux[i] = 'a';
                break;
            case 'Á': case 'À': case 'Ã': case 'Â':
                aux[i] = 'A';
                break;
        
            }
        }
        
        p.push_back(aux);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        cout << p[i] << endl;
    }
    return 0;
}
