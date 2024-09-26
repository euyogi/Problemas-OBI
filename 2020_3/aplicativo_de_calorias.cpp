// 2020 Fase 3: Aplicativo de Calorias (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f3/calorias/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int e1, e2, e3, x;
    cin >> e1 >> e2 >> e3 >> x;
    if (e2 - e1 <= x)
        cout << e2 << '\n';
    else
        cout << e3 << '\n';
}
