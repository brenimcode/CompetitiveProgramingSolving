/*
beecrowd | 1103
Alarme Despertador
Maratona de Programação da SBC  Brasil


*/
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;
#define int long long


int32_t main() {
     int x1, y1, x2, y2;
    
    while (cin >> x1 >> y1 >> x2 >> y2) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) 
            break; // Termination case

        // If the positions are the same, no move is needed
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            continue;
        }

        // If the positions are in the same row or column, only one move is needed
        if (x1 == x2 || y1 == y2) {
            cout << 1 << endl;
            continue;
        }

        // If the positions are on the same diagonal, only one move is needed
        if (abs(x1 - x2) == abs(y1 - y2)) {
            cout << 1 << endl;
            continue;
        }

        // Otherwise, it will always take two moves
        cout << 2 << endl;
    }

    return 0;
}
