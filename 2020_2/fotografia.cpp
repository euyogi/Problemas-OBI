// 2020 Fase 2: Fotografia (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f2/fotografia/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, l, n, x, y;
    cin >> a >> l >> n;

    int menor_area = INT_MAX, indice = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if ((x >= a and y >= l) or (y >= a and x >= l)) {
            int area_moldura = x * y;
            if (area_moldura < menor_area) {
                menor_area = area_moldura;
                indice = i;
            }
        }
    }

    cout << indice << '\n';
}
