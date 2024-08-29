  #include <bits/stdc++.h>

    using namespace std;

    const int MAXN = 200100;
    #define int long long

    int bit[MAXN], n;

    // soma v em V[x]
   void upd(int x, int v){
    
    //Itera sobre todos indices "relevantes", o pai do indice i é ( i + lsb(i) )
    // lsb(i) = (x * -x);
    while(x <= n){ 
        bit[x] += v;
        x += (x & -x);
    }
}

    // soma de [1, x]
    int soma(int x)
    {
        int ans = 0;

        for (; x > 0; x -= (x&-x))
            ans += bit[x];

        return ans;
    }

    // soma de [x,y]
    int soma_inter(int x,int y){
        return soma(y) - soma(x-1);
    }

    // setar o valor v no indice X
    void setar(int x, int v)
    {
        upd(x,v - soma_inter(x,x));
    }

    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int cases = 1;

        while(cin >> n)
        {
            if(n == 0) break;
            if(cases > 1) cout << endl;
            cout << "Case " << cases++ << ":\n";


            for(int i = 0; i<= n+10; i++)
            {
                bit[i] = 0;
            }

            // Inicializando a BIT
            for(int i = 1; i<= n; i++)
            {
                int aux;
                cin >> aux;
                upd(i,aux);

            }

            string str;
            int num1,num2;

            while(true)
            {
                cin >> str;
                if(str == "END")
                {
                    break;
                }
                cin >> num1 >> num2;

                if(str == "M")
                {
                    cout << soma_inter(num1,num2) << endl;
                }
                else if(str == "S")
                {
                    setar(num1,num2);
                }

            }
        }

    }
