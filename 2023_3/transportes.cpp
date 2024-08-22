// 2023 Fase 3: Transportes (https://neps.academy/br/exercise/2571)

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s, vector<int>& precos) {
    vector<map<int, int>> dists(g.size());
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    // -1 é onde eu guardo o menor tempo possível
    dists[s][-1] = 0;
    pq.emplace(0, s, -1);
    while (!pq.empty()) {
        auto [t, u, t1] = pq.top();
        pq.pop();
        if (t > dists[u][t1]) continue;
        for (auto [v, t2] : g[u]) {
            int w = (t1 == t2 ? 0 : precos[t2]);
            // eu vou se o tempo for menor que o marcado para esse sistema
            // e também tem que ser menor que o menor possível somado
            // do tempo de trocar para esse sistema, se não nem vale apena
            if ((dists[v].count(t2) == 0 or t + w < dists[v][t2]) and
                (dists[v].count(-1) == 0 or t + w < dists[v][-1] + precos[t2])) {
                if (dists[v].count(-1) == 0 or t + w < dists[v][-1])
                    dists[v][-1] = t + w;
                dists[v][t2] = t + w;
                pq.emplace(t + w, v, t2);
            }
        }
    }
    vector<int> ds(g.size());
    for (int i = 0; i < dists.size(); ++i)
        ds[i] = (dists[i].count(-1) == 0 ? -1 : dists[i][-1]);
    return ds;
}

signed main() {
    int n, m, k, u, v, t, a, b;
    cin >> n >> m >> k;

    vector<int> precos(k);
    for (int& p : precos) cin >> p;

    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        cin >> u >> v >> t;
        g[u].emplace_back(v, --t);
        g[v].emplace_back(u, t);
    }

    cin >> a >> b;
    auto dists = dijkstra(g, a, precos);
    cout << dists[b] << '\n';
}
