#include <bits/stdc++.h>

using namespace std;

#define par pair<int, int> // (x,y)
#define x first // par.x
#define y second // par.y

#define int long long

par p[10]; // Array de pontos

// Função para retornar o sinal de um número
int sinal(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

// Função para calcular a distância ao quadrado entre dois pontos A e B
int dist2(par a, par b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// Função para calcular o produto vetorial dos vetores AB e AC
int cross(par a, par b, par c) {
    par x = {b.x - a.x, b.y - a.y};
    par y = {c.x - a.x, c.y - a.y};
    return x.x * y.y - x.y * y.x;
}

// Função para verificar se três pontos A, B e C são colineares
bool col(par a, par b, par c) {
    return (cross(a, b, c) == 0);
}

// Funções de verificação conforme os checks do problema
bool check1() {
    return (dist2(p[1], p[2]) + dist2(p[1], p[3]) > dist2(p[2], p[3]));
}

bool check2() {
    return (dist2(p[1], p[2]) == dist2(p[1], p[3]));
}

bool check3() {
    return (col(p[2], p[3], p[4]) && col(p[2], p[3], p[5]));
}

bool check4() {
    return (p[2].x + p[3].x == p[4].x + p[5].x && p[2].y + p[3].y == p[4].y + p[5].y);
}

bool check5() {
    return (dist2(p[2], p[3]) > dist2(p[4], p[5]));
}

bool check6() {
    return (dist2(p[4], p[6]) + dist2(p[4], p[2]) == dist2(p[2], p[6]) && dist2(p[5], p[7]) + dist2(p[5], p[3]) == dist2(p[3], p[7]));
}

bool check7() {
    return (dist2(p[4], p[6]) == dist2(p[5], p[7]));
}

bool check8() {
    return (sinal(cross(p[2], p[3], p[1])) * sinal(cross(p[2], p[3], p[6])) == -1);
}

// Função principal
int main() {
    // Leitura das coordenadas dos pontos
    for (int i = 1; i <= 7; i++) {
        cin >> p[i].x >> p[i].y;
    }

    // Verifica se todas as condições são atendidas
    cout << (check1() && check2() && check3() && check4() && check5() && check6() && check7() && check8() ? 'S' : 'N') << endl;

    return 0;
}
