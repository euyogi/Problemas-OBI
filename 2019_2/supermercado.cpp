// 2019 Fase 2: Supermercado (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f2/supermercado/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, g;
    cin >> n;

    long double p, menor;
    cin >> p >> g;
    menor = p * 1000.0L / g;
    while (--n) {
        cin >> p >> g;
        menor = min(menor, p * 1000.0L / g);
    }

    cout << fixed << setprecision(2) << menor << '\n';
}
