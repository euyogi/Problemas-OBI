// 2015 Fase 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

ll k;
bitset<(ll)1e5 + 10> has_people;

vll dijkstra(vvpll& g, ll s) {
    vll dists(g.size(), LONG_LONG_MAX);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.emplace(0, s, 0);
    dists[s] = 0;
    while (!pq.empty()) {
        auto [t, u, u_dist_to_last_person] = pq.top(); pq.pop();
        for (auto [w, v] : g[u]) {
            ll v_dist_to_last_person = w;
            if (not has_people[u])
                v_dist_to_last_person += u_dist_to_last_person;

            ll nt = t + w;
            if (has_people[v])
                nt -= min(v_dist_to_last_person, k);

            if (nt < dists[v]) {
                dists[v] = nt;
                pq.emplace(nt, v, v_dist_to_last_person);
            }
        }
    }
    return dists;
}

signed main() {
    ll n, m, c;
    cin >> n >> m >> c >> k;

    for (ll i = 0, x; i < c; ++i) {
        cin >> x;
        has_people[x] = true;
    }

    vvpll g(n + 1);
    for (ll i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
    }

    auto dists = dijkstra(g, 1);
    if (dists[n] == LONG_LONG_MAX)
        dists[n] = -1;

    cout << dists[n] << '\n';
}
