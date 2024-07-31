// 2021 Fase 2: Duplas de tênis (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/tenis/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> xs {a, b, c, d};
    sort(xs.begin(), xs.end());

    cout << abs((xs[0] + xs[3]) - (xs[1] + xs[2])) << '\n';
}
