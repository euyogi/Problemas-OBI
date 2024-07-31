// 2021 Fase 2: Sanduíche (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/sanduiche/)

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;

int sanduiches(int i, int pegos, vector<pair<int, int>>& proibido) {
    for (auto& [x, y] : proibido)
        if (pegos & (1 << x) and pegos & (1 << y))
            return 0;

    if (i == n + 1) return 1;
    return sanduiches(i + 1, pegos, proibido) + sanduiches(i + 1, pegos | (1 << i), proibido);
}

signed main() {
    cin >> n >> m;

    vector<pair<int, int>> proibido(m);
    for (int i = 0; i < m; ++i)
        cin >> proibido[i].x >> proibido[i].y;

    cout  << sanduiches(1, 0, proibido) - 1 << '\n';
}
