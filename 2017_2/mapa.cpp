// 2017 Fase 2: Mapa (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/mapa/)

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;

signed main() {
    int l, c;
    cin >> l >> c;

    vector<string> g(l);
    pii s;
    for (int i = 0; i < l; ++i) {
        cin >> g[i];
        auto pos = g[i].find('o');
        if (pos != string::npos)
            s = { i, pos };
    }

    vpii ds = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    auto dfs = [&](auto& self, pii u, pii p) -> pii {
        auto [y, x] = u;
        for (auto [oy, ox] : ds) {
            pii npos = { y + oy, x + ox };
            auto [ny, nx] = npos;
            if (nx >= 0 and ny >= 0 and nx < c and ny < l and npos != p and g[ny][nx] == 'H')
                return self(self, npos, u);
        }
        return u;
    };

    auto [rx, ry] = dfs(dfs, s, { -1, -1 });
    cout << rx + 1 << ' ' << ry + 1 << '\n';
}
