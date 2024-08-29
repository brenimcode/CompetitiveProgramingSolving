    #include <bits/stdc++.h>

    using namespace std;
    #define DEBUG(x) cout << #x << " >>>> " << x << endl;
    #define NMAX 30

    int n, m, q;
    char mat[NMAX][NMAX];
    int ql[8] = {0, 0, 1, -1, -1, 1, -1, 1};
    int qc[8] = {1, -1, 0, 0, -1, 1, 1, -1};


    void jogoDaVida(int i, int j)
    {

        int vivas = 0;
        for (int k = 0; k < 8; k++)
        {
            int vizI = i + ql[k];
            int vizJ = j + qc[k];

            if (vizI < 0 || vizJ < 0 || vizI >= n || vizJ >= n)
                continue;

            if (mat[vizI][vizJ] == '1')
            {
                vivas++;
            }
        }

        // se tiver morta e tiver 3 vizinhas vivas.
        if (vivas == 3 && mat[i][j] == '0')
        {
            mat[i][j] = '1';
        } // tiver viva e vivas < 2
        else if (mat[i][j] == '1' && vivas < 2)
        {
            mat[i][j] = '0';
        }
        else if (mat[i][j] == '1' && vivas > 3)
        {
            mat[i][j] = '0';
        }
    }

    void imprimeMat()
    {
        printf("\n========-==========-=======-======\n");
        for (int it = 0; it < n; it++)
        {
            for (int jt = 0; jt < n; jt++)
            {
                cout << '[' << mat[it][jt] << ']';
            }
            printf("\n");
        }
        printf("\n========-==========-=======-======\n");
    }

    int32_t main()
    {
        cin >> n >> q;
        // leitura
        cin.ignore();
        for (int i = 0; i < n; i++)
        {

            string aux;
            getline(cin,aux);

            for (int j = 0; j < (int) aux.size(); j++)
            {
                mat[i][j] = aux[j];
            }
        }

        for (int qtd = 0; qtd < q; qtd++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    jogoDaVida(i, j);
                }
            }
            imprimeMat();
        }

        //imprimeMat();

        return 0;
    }
