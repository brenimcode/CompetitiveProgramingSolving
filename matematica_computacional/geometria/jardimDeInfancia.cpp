#include <bits/stdc++.h>

using namespace std;
#define int long long
#define DEBUG(x) cout << #x << " >>>> " << x << endl;
#define PI 3.1415
#define par pair<int, int> // (x,y)
#define x first // par.x
#define y second // par.y
vector<par> p; // {x,y}

// ---- IMPLEMENTAÇÕES DE PRODUTO(VETORIAL/ESCALAR).

// Função para verificar se três pontos são colineares usando a estrutura 'par'
bool collinear(par a, par b, par c) {
    // Vetores ab e ac
    par ab = {b.x - a.x, b.y - a.y};
    par ac = {c.x - a.x, c.y - a.y};

    // Calculando o produto vetorial (cross product) entre ab e ac
    int cross_product = ab.x * ac.y - ab.y * ac.x;

    // Se o produto vetorial for zero, os pontos são colineares
    return cross_product == 0;
}

// Função para verificar se quatro pontos são colineares
bool collinear(par a, par b, par c, par d) {
    // Verifica se três pontos quaisquer são colineares
    return collinear(a, b, c) && collinear(a, b, d);
}

int dist_pontos(par a, par b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int produtoEscalar(par a, par b) {
    DEBUG(a.x * b.x + a.y * b.y);
    return a.x * b.x + a.y * b.y;
}

int produtoVetorial(par u, par v) {
    return u.x * v.y - u.y * v.x;
}

// Função para verificar se o ângulo no ponto 'a' é agudo
bool eh_agudo_A(par p1, par p2, par p3) {
    return (dist_pontos(p1, p2) + dist_pontos(p1, p3) > dist_pontos(p2, p3));
}

bool isPerpendiculares(par a, par b, par c, par d) {
    // segmentos ab, cd
    par ab = {b.x - a.x, b.y - a.y};
    par cd = {d.x - c.x, d.y - c.y};
    return produtoEscalar(ab, cd) == 0;
}

bool isPerpendicularess(){
	return (dist_pontos(p[6],p[4]) + dist_pontos(p[4],p[2])==dist_pontos(p[2],p[6])); //d(P7,P5)2+d(P5,P3)2=d(P3,P7)2
}


// Função para verificar se os pontos médios dos segmentos coincidem
bool pontosMediosCoincidem(par p2, par p3, par p4, par p5) {
    // Calcula os pontos médios dos segmentos P2P3 e P4P5
    par medioP2P3 = {(p2.x + p3.x) * 1000 / 2, (p2.y + p3.y) * 1000 / 2};
    par medioP4P5 = {(p4.x + p5.x) * 1000 / 2, (p4.y + p5.y) * 1000 / 2};

    // Verifica se os pontos médios são iguais
    return medioP2P3 == medioP4P5;
}

// Função para verificar se duas retas se intersectam em um único ponto
bool areLinesIntersectingAtOnePoint(par a, par b, par c, par d) {
    // Vetores diretores das retas
    par ab = {b.x - a.x, b.y - a.y};
    par cd = {d.x - c.x, d.y - c.y};

    // Verificar se os vetores são paralelos (produto vetorial zero)
    if (produtoVetorial(ab, cd) == 0) {
        return false; // Retas são paralelas ou coincidentes
    }

    // Verificar se os pontos coincidem (retas coincidentes)
    if ((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y) ||
        (b.x == c.x && b.y == c.y) || (b.x == d.x && b.y == d.y)) {
        return false; // Retas são coincidentes
    }

    return true; // Retas se intersectam em exatamente um ponto
}



int32_t main() {
    int n = 7;
    while (n--) {
        int xi, yi;
        cin >> xi >> yi;
        p.push_back({xi, yi});
    }

    /*
    Verifique se:
    O ângulo P2P1P3 é agudo (vértice em P1);
    Os segmentos P1P2 e P1P3 têm o mesmo comprimento;
    Os pontos P2, P3, P4 e P5 são colineares;
    Os pontos médios dos segmentos P2P3 e P4P5 são coincidentes;
    O segmento P2P3 tem comprimento maior que o segmento P4P5;
    Os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3;
    Os segmentos P4P6 e P5P7 têm o mesmo comprimento;
    Os pontos P1 e P6 devem estar separados pela reta que contém o segmento P2P3. Formalmente, o segmento 
    P1P6 deve interceptar a reta que contém o segmento P2P3 em um único ponto.
    */
   DEBUG(isPerpendicularess());
   
    if (dist_pontos(p[0], p[1]) == dist_pontos(p[0], p[2]) && collinear(p[1], p[2], p[3], p[4]) &&
        dist_pontos(p[1], p[2]) > dist_pontos(p[3], p[4]) && pontosMediosCoincidem(p[1], p[2], p[3], p[4]) &&
        isPerpendicularess() &&
        dist_pontos(p[3], p[5]) == dist_pontos(p[4], p[6]) && areLinesIntersectingAtOnePoint(p[0], p[5], p[1], p[2]) &&
        eh_agudo_A(p[0], p[1], p[2])) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
