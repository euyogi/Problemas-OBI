// 2017 Fase 2: Frete (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/frete/)

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

vi dijkstra(vvpii& g, int s) {
    vi dists(g.size(), INT_MAX);
    priority_queue<pii, vpii, greater<>> pq;
    pq.emplace(0, s);
    dists[s] = 0;
    while (!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();
        for (auto& [w, v] : g[u])
            if (t + w < dists[v]) {
                pq.emplace(t + w, v);
                dists[v] = t + w;
            }
    }
    return dists;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vvpii g(n + 1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }

    cout << dijkstra(g, 1)[n] << '\n';
}
