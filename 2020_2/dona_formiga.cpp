// 2020 Fase 2: Dona Formiga (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f2/formiga/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int s, t, p, u, v;
    cin >> s >> t >> p;

    vector<int> hs(s + 1);
    for (int i = 1; i <= s; ++i)
        cin >> hs[i];

    vector<vector<int>> g(s + 1);
    while (t--) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> vis(s + 1);

    auto dfs = [&](auto&& self, int u) -> int {
        if (vis[u]) return vis[u];
        vis[u] = 1;
        for (int v : g[u]) if (hs[u] > hs[v])
            vis[u] = max(vis[u], 1 + self(self, v));
        return vis[u];
    };

    dfs(dfs, p);
    int ans = 0;
    // considerando todas viagens
    for (int u : vis) ans += (u > 0);
    // ans = vis[p]; // única viagem
    cout << ans - 1 << '\n';
}
