// 2020 Fase 3: Trem da Mina (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f3/trem/)

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
    vector<int> dist(g.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (dist[u] < t) continue;
        for (auto [w, v] : g[u])
            if (t + w < dist[v]) {
                dist[v] = t + w;
                pq.emplace(t + w, v);
            }
    }
    return dist;
}

signed main() {
    int n, m, q;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }

    vector<int>  sz(n + 1);
    vector<bool> vs(n + 1);
    vector<pair<int, int>> ant(n + 1);

    auto dfs = [&](auto&& self, int u) -> void {
        vs[u] = true;
        for (auto [w, v] : g[u])
            if (!vs[v]) {
                ant[v] = {w, u};
                self(self, v);
            }
            else if (sz[u] == 0 and ant[u].second != v) {
                int peso = w;
                int at = u;
                while (at != v) {
                    peso += ant[at].first;
                    at    = ant[at].second;
                }

                at = u;
                sz[at] = peso;
                while (at != v) {
                    at     = ant[at].second;
                    sz[at] = peso;
                }
            }
    };

    dfs(dfs, 1);

    cin >> q;

    while (q--) {
        int u, c;
        cin >> u >> c;
        auto dist = dijkstra(g, u);

        int res = INT_MAX;
        for (int i = 1; i <= n; ++i)
            if (sz[i] >= c)
                res = min(res, 2 * dist[i] + sz[i]);

        if (res == INT_MAX)
            cout << "-1\n";
        else
            cout << res << '\n';
    }
}
