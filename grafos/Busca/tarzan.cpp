#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl
#define NMAX 105
typedef pair<int,int> par;

int dI[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1}; // (0) = (V), (1) = (A), (2) = (>) ,(3) = (<)

int n,d;

void dfs(int i, int j)
{
    mat[i][j] = 2;
    for (int k = 0; k < 4; k++)
    {
        for (int l = 1; l <= d; l++)
        {
            
        
        int vizI = i;
        int vizJ = j;
        vizI += dI[k]*l;
        vizJ +=  dj[k]*l;

        if (vizI < 0 || vizI > n || vizJ < 0 || vizJ > n)
            continue;

        if (mat[vizI][vizJ] == 1)
        {   
            sum++;
            dfs(vizI,vizJ);
        }

        }
    }
}

void printa(){
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << ' ';
            
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> d;
    vector<par> pos; // (i,j)
    vector<par> vizinhos[NMAX];

    int  a, b;

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        pos.push_back(make_pair(a,b));
    }

    bool ver = true;

    for (int i = 1; i <= n; i++)
    {

        int c_i = pos[i].first;
        int c_j = pos[i].second;
        par x = make_pair(pos[i].first,pos[i].second);

        for (int j = i; j <= n; j++)
        {

            int c2_i = pos[j].first;
            int c2_j = pos[j].second;
            par y = make_pair(pos[j].first,pos[j].second);

            int dist = sqrt(pow(c_i-c2_i,2) + pow(c_j-c2_j,2));
            
            if(d < dist){
                
                ver = false;
            }

        }
        
    }
    

    if(ver)
        cout << "S" << endl;
    else
        cout << "N" << endl;


    return 0;
}