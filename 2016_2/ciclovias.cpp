// 2016 Fase 2: Ciclovias (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/ciclovias/)
// TODO: MELHORAR TEMPO!!!

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; ++i)
        sort(all(g[i]), greater<>());

    vector<unordered_map<int, int>> dp(n + 1);

    auto dfs = [&](auto& self, int u, int p) -> int {
        int& memo = dp[u][p];
        if (memo) return memo;
        memo = 1;
        for (int v : g[u]) {
            if (v <= p) break;
            memo = max(self,(self, v, u) + 1, memo);
        }
        return memo;
    };

    cout << dfs(dfs, 1, 0);
    for (int i = 2; i <= n; ++i)
        cout << ' ' << dfs(dfs, i, 0);
    cout << '\n';
}
