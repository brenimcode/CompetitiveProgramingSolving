#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " --->>> " << x << endl
#define NMAX 55

int32_t main()
{
    int n;
    cin >> n; // n == numero de diretor, k = duração maxima
    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // existem 4 casos.
    vector<int> linha;
    vector<int> linhaOrdenada;

    vector<int> coluna;
    vector<int> colunaOrdenada;

    // Verifico se a primeira linha esta ordenada
    for (int j = 0; j < n; j++)
    {
        linha.push_back(mat[0][j]);
    }
    linhaOrdenada = linha;
    sort(linhaOrdenada.begin(), linhaOrdenada.end());

    // Verifica se a coluna esta ordenada também
    for (int j = 0; j < n; j++)
    {
        coluna.push_back(mat[j][0]);
    }
    colunaOrdenada = coluna;
    sort(colunaOrdenada.begin(), colunaOrdenada.end());

    if ((linha == linhaOrdenada) && (coluna == colunaOrdenada))
    {
        cout << 0 << endl;
        return 0;
    }
    /* ---------------------------------------- |||||2º CASO 1-LINHA INVERSA |||||||| ----------------------------------- */
    // Sempre a coluna recebe a ultima linha.

    linha.clear();
    linhaOrdenada.clear();
    coluna.clear();
    colunaOrdenada.clear();

    // pego a linha da primeira rotação
    for (int j = 0; j < n; j++)
    {
        linha.push_back(mat[j][n - 1]);
    }

    linhaOrdenada = linha;
    sort(linhaOrdenada.begin(), linhaOrdenada.end());

    // Verifico se a primeira linha (de tras para frente) esta ordenada
    // PEGO A COLUNA DA PRIMEIRA ROTAÇÃO ANTIHORARIA
    for (int j = n - 1; j >= 0; j--)
    {
        coluna.push_back(mat[0][j]);
    }
    colunaOrdenada = coluna;
    sort(colunaOrdenada.begin(), colunaOrdenada.end());

    /*
    cout << "\nLINHA:\n";
    for (int j = 0; j < n; j++)
    {
        cout << "-- { " << linha[j] << " } --" << endl;
    }

    cout << "\nCOLUNA\n";
    for (int j = 0; j < n; j++)
    {
        cout << "-- { " << coluna[j] << " } --" << endl;
    }
    */

    if ((linha == linhaOrdenada) && (coluna == colunaOrdenada))
    {
        cout << 1 << endl;
        return 0;
    }

    /* ---------------------------------------- |||||3º CASO (N-1)-LINHA INVERSA |||||||| ----------------------------------- */
    // Sempre a coluna recebe a ultima linha.

    linha.clear();
    linhaOrdenada.clear();
    coluna.clear();
    colunaOrdenada.clear();

    // pego a linha da segunda rotação
    for (int j = n-1; j >=0; j--)
    {
        linha.push_back(mat[n-1][j]);
    }

    linhaOrdenada = linha;
    sort(linhaOrdenada.begin(), linhaOrdenada.end());

    // Verifico se a primeira linha (de tras para frente) esta ordenada
    // PEGO A COLUNA DA PRIMEIRA ROTAÇÃO ANTIHORARIA
    for (int j = n - 1; j >= 0; j--)
    {
        coluna.push_back(mat[j][n-1]);
    }
    colunaOrdenada = coluna;
    sort(colunaOrdenada.begin(), colunaOrdenada.end());

    if ((linha == linhaOrdenada) && (coluna == colunaOrdenada))
    {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;

    return 0;
}
