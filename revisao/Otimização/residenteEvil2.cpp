#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define double long double
#define NMAX 8
#define CMAX 1015

map<string, double> armas_mapa = {
    {"HANDGUN", 2.0},
    {"RED9", 3.5},
    {"BLACKTAIL", 3.5},
    {"MATILDA", 2.0},
    {"HANDCANNON", 60.0},
    {"STRIKER", 12.0},
    {"TMP", 1.2},
    {"RIFLE", 12.0}
};

map<string, double> monstros_mapa = {
    {"GANADOS", 50.0},
    {"COBRAS", 40.0},
    {"ZEALOT", 75.0},
    {"COLMILLOS", 60.0},
    {"GARRADOR", 125.0},
    {"LASPLAGAS", 100.0},
    {"GATLINGMAN", 150.0},
    {"REGENERATOR", 250.0},
    {"ELGIGANTE", 500.0},
    {"DR.SALVADOR", 350.0}
};

int municao[NMAX]; // potencias e municaos das armas
double potencia[NMAX];
double tab[NMAX][CMAX]; // Tabela de DP para salvar os estados, Municao e POTENCIA.
int QA; // Quantidade de armas

double knap_iterativo(int capacidade) {
    // Inicializando a tabela com zeros
    for (int i = 0; i <= QA; ++i) {
        for (int j = 0; j <= capacidade; ++j) {
            tab[i][j] = 0.0;
        }
    }

    // Preenchendo a tabela iterativamente
    for (int i = 1; i <= QA; ++i) {
        for (int j = 0; j <= capacidade; ++j) {
            if (municao[i-1] <= j) {
                tab[i][j] = max(tab[i-1][j], potencia[i-1] * municao[i-1] + tab[i-1][j - municao[i-1]]);
            } else {
                tab[i][j] = tab[i-1][j];
            }
        }
    }

    return tab[QA][capacidade];
}

int32_t main() {
    _

    while (cin >> QA) {
        // Reinicializa os vetores a cada iteração
        for (int i = 0; i < QA; ++i) {
            municao[i] = 0;
            potencia[i] = 0.0;
        }

        for (int i = 0; i < QA; i++) {
            string nome;
            cin >> nome >> municao[i];
            potencia[i] = armas_mapa[nome];
        }

        int QM; // Quantidade de monstros
        cin >> QM;

        // Calculando o dano necessário para matar todos os monstros
        double dano_necessario = 0.0;
        for (int i = 0; i < QM; i++) {
            string nome;
            int qtd;
            cin >> nome >> qtd;
            dano_necessario += monstros_mapa[nome] * qtd;
        }

        int QB; // Quantidade máxima de balas que pode carregar
        cin >> QB;

        // Calcula o máximo de dano que ele vai infligir com as armas
        double dano_infligido = knap_iterativo(QB);

        if (dano_infligido >= dano_necessario) {
            cout << "Missao completada com sucesso" << endl << endl;
        } else {
            cout << "You Are Dead" << endl << endl;
        }
    }

    return 0;
}
