#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NMAX 10010


int32_t main()
{
    int n;
    cin >> n;

    stack<int> deque;
    stack<int> descart;
    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        deque.push(aux);
    }
    descart.push(deque.top());
    deque.pop();

    int ans = 0;
    while(!deque.empty()){
        int topoDeque = deque.top();
        int topoDesc = descart.top();
        deque.pop();
        descart.push(topoDeque);
        if(topoDesc%topoDeque == 0){
            ans++;  // é divisivel
        }
    }

    cout << ans << endl;
}