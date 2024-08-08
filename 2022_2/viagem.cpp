// 2022 Fase 2: Viagem (https://neps.academy/br/exercise/2132)

#include <bits/stdc++.h>
using namespace std;

#define int long long

using ti = tuple<int, int, int>;
using vti = vector<ti>;
using vvti = vector<vti>;

vector<int> dijkstra(vvti& g, int s, int lim) {
    vector<int> dists(g.size(), INT_MAX), prices = dists;
    priority_queue<ti, vti, greater<>> pq;
    dists[s] = 0, prices[s] = 0;
    pq.emplace(0, 0, s);
    while (!pq.empty()) {
        auto [t, pu, u] = pq.top();
        pq.pop();
        for (auto [w, pv, v] : g[u]) {
            if (pu + pv <= lim and t + w < dists[v]) {
                dists[v] = t + w;
                prices[v] = pu + pv;
                pq.emplace(t + w, pu + pv, v);
            }
            // pode ser que alguma rota tenha um preço
            // menor, nesse caso, o tempo vai ser maior
            // mas vai liberar as rotas que não fomos
            // porque atingimos o limite de preço
            else if (pu + pv < prices[v]) {
                prices[v] = pu + pv;
                pq.emplace(t + w, pu + pv, v);
            }
        }
    }
    return dists;
}

signed main() {
    int v, n, m, a, b, t, p, x, y;
    cin >> v >> n >> m;

    vvti g(n + 1);
    while (m--) {
        cin >> a >> b >> t >> p;
        g[a].emplace_back(t, p, b);
        g[b].emplace_back(t, p, a);
    }

    cin >> x >> y;
    auto dists = dijkstra(g, x, v);
    cout << (dists[y] == INT_MAX ? -1 : dists[y]) << '\n';
}
