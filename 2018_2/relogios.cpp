// 2018 Fase 2: Relógios (https://olimpiada.ic.unicamp.br/pratique/p1/2018/f2/relogios/)

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ds {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<vector<int>> dijkstra(vector<vector<int>>& g, int sy, int sx, int k) {
    vector dists(g.size(), vector<int>(g[0].size(), INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dists[sy][sx] = 0;
    pq.emplace(0, sy, sx);
    while (!pq.empty()) {
        auto [t, posy, posx] = pq.top();
        pq.pop();
        for (auto [oy, ox] : ds) {
            int ny = oy + posy, nx = ox + posx;
            if (ny < 0 or nx < 0 or ny >= g.size() or nx >= g[0].size())
                continue;
            int h = g[posy][posx], nh = g[ny][nx];
            // normal -> quebrado
            if (h == -1 and nh != -1) {
                int diff = nh - t % k;
                if (diff <= 0) diff += k;
                if (t + diff < dists[ny][nx]) {
                    dists[ny][nx] = t + diff;
                    pq.emplace(t + diff, ny, nx);
                }
            }
            // normal -> normal, quebrado -> normal, quebrado -> quebrado
            // (caso 5 -> 0 é importante)
            else if (t + 1 < dists[ny][nx] and (nh == -1 or (h + 1) % k == nh)) {
                dists[ny][nx] = t + 1;
                pq.emplace(t + 1, ny, nx);
            }
        }
    }
    return dists;
}

int main() {
    int l, c, k;
    cin >> l >> c >> k;

    vector g(l, vector<int>(c));
    for (auto& lin : g)
        for (auto& col : lin)
            cin >> col;

    auto dists = dijkstra(g, 0, 0, k);
    cout << (dists[l - 1][c - 1] == INT_MAX ? -1 : dists[l - 1][c - 1]) << '\n';
}
