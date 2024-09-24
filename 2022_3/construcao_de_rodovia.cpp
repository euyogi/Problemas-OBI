#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> g(n + 1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].emplace(v);
    }

    for (int u = 0; u <= n; ++u)
        for (int v : g[u])
            for (int w : g[v])
                if (u != w and g[u].find(w) == g[u].end()) {
                    cout << u << ' ' << w << '\n';
                    return 0;
                }

    cout << "-1\n";
}
