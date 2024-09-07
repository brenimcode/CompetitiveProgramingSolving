#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define int long long

int32_t main()
{
    
    int num; // 1 a 50
    while (cin >> num)
    {
        if(num == 0)
            break;

        vector<int> pilha;
        queue<int> discarted;

            // carta 1 no topo e a carta n na base. 
            for(int i = num; i > 0;i--) {
                pilha.push_back(i);
            }
        
        while (pilha.size() >= 2)
        {
            // Jogo fora a carta do topo
            discarted.push(pilha.back());
            pilha.pop_back();
            // pego a carta do topo e jogo ela para a base.
            int topo = pilha.back();
            pilha.pop_back();
            pilha.insert(pilha.begin(),topo);
        }

        cout << "Discarded cards: ";
        while (!discarted.empty())
        {
            cout << discarted.front();
            discarted.pop();
            if(!discarted.empty()){
               cout << ", ";
            }
        }
        cout << endl;
        cout << "Remaining card: ";
        while (!pilha.empty())
        {
            cout << pilha.back();
            pilha.pop_back();
            if(!pilha.empty()){
               cout << ", ";
            }
        }
        cout << endl;

    }

    return 0;
}