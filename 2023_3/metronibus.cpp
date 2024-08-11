// 2023 Fase 3: Metrônibus (https://neps.academy/br/exercise/2567)

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs01(vector<vector<int>>& metro, vector<vector<int>>& onibus, int s) {
    vector<int> dists(metro.size(), 1e9);
    enum {
        NENHUM, METRO, ONIBUS
    };
    deque<pair<int, int>> dq;
    dists[s] = 0;
    dq.emplace_front(s, NENHUM);
    while (!dq.empty()) {
        auto [u, em] = dq.front();
        dq.pop_front();
        for (int v : metro[u]) {
            if (em == METRO and dists[u] < dists[v]) {
                dists[v] = dists[u];
                dq.emplace_front(v, METRO);
            }
            else if (dists[u] + 1 < dists[v]) {
                dists[v] = dists[u] + 1;
                dq.emplace_back(v, METRO);
            }
        }
        for (int v : onibus[u]) {
            if (em == ONIBUS and dists[u] < dists[v]) {
                dists[v] = dists[u];
                dq.emplace_front(v, ONIBUS);
            }
            else if (dists[u] + 1 < dists[v]) {
                dists[v] = dists[u] + 1;
                dq.emplace_back(v, ONIBUS);
            }
        }
    }
    return dists;
}

signed main() {
    int n, k1, k2, p, a, b;
    cin >> n >> k1 >> k2 >> p;

    vector<vector<int>> metro(n + 1), onibus(n + 1);

    for (int i = 0, u, v; i < k1; ++i) {
        cin >> u >> v;
        metro[u].emplace_back(v);
        metro[v].emplace_back(u);
    }

    for (int i = 0, u, v; i < k2; ++i) {
        cin >> u >> v;
        onibus[u].emplace_back(v);
        onibus[v].emplace_back(u);
    }

    cin >> a >> b;

    auto dists = bfs01(metro, onibus, a);
    cout << (dists[b] != 1e9 ? dists[b] * p : -1) << '\n';
}
