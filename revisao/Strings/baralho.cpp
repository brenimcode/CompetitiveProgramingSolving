#include <bits/stdc++.h>

#define DEBUG(x) cout << #x << " >>>> " << x << endl

using namespace std;

int main() {
    string a,b;

    getline(cin,a);
    int t = a.size();

    vector<int> naipes[4]; // [C] [E] [U] [P]
    for (int i = 0; i < t; i+=3)
    {
        int num = 10*(a[i] - '0') + (a[i+1] - '0');
        int naipe;
        switch (a[i+2])
        {
        case 'C':
            naipe = 0;
            break;
        case 'E':
            naipe = 1;
            break;
        case 'U':
            naipe = 2;
            break;
        case 'P':
            naipe = 3;
            break;
        }
        naipes[naipe].push_back(num);
    }

    for (int i = 0; i < 4; i++)
    {
        int vet[14];
        for (int j = 1; j <= 13; j++)
        {
            vet[j] = 0;
        }
        bool ver = false;
        for (int j = 0; j < (int) naipes[i].size(); j++)
        {
            if(vet[naipes[i][j]] == 1){ // repetição
                ver = true;
                break;
            }
            else{
                vet[naipes[i][j]] = 1;
            }
        }
        
        if(ver) {
            cout << "erro" << endl;
        }else{
            int quantidade = 0;
            for (int j = 1; j <= 13; j++)
            {
                if(vet[j] == 0){
                    quantidade++;
                }
            }

            cout << quantidade << endl;

        }

    }
    

    return 0;
}
