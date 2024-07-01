#include <bits/stdc++.h>

using namespace std;
#define int long long

#define PI 3.1415

struct Pt
{
    int x, y;
    Pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Pt operator+(const Pt &o) { return Pt(x + o.x, y + o.y); }                 // soma de vetores
    Pt operator-(const Pt &o) { return Pt(x - o.x, y - o.y); }                 // subtração de vetores
    void operator+=(const Pt &o) { x += o.x, y += o.y; }                       // somar vetores com o operador +=
    void operator-=(const Pt &o) { x -= o.x, y -= o.y; }                       // subtrair vetores com o operador -=
    long long operator*(const Pt &o) { return 1ll * x * o.x + 1ll * y * o.y; } // dot - produto escalar
    long long operator/(const Pt &o) { return 1ll * x * o.y - 1ll * y * o.x; } // cross - produto vetorial
};

// ---- IMPLEMENTAÇÕES DE PRODUTO(VETORIAL/ESCALAR)

// verifica se 3 pontos sao colineares.
bool collinear(Pt a, Pt b, Pt c)
{
    return (b - a) / (c - a) == 0;
}

// Ver mais aplicações de produto vetorial e escalar


int32_t main()
{
    cout << ;

    return 0;
}
