// 2019 Fase 2: Robô marciano (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f2/robo/)

#include <bits/stdc++.h>
using namespace std;

using Quadrado = pair<pair<int, int>, pair<int, int>>;

// x1 < x2, x3 < x4
// y1 < y2, y3 < y4
#define x1 P.first.first
#define y1 P.first.second
#define x2 P.second.first
#define y2 P.second.second
#define x3 Q.first.first
#define y3 Q.first.second
#define x4 Q.second.first
#define y4 Q.second.second

int distanciaQuadrados(const Quadrado& P, const Quadrado& Q) {
    int dist_x = (x1 > x4 or x2 < x3 ? INT_MAX : 0);
    int dist_y = (y1 > y4 or y2 < y3 ? INT_MAX : 0);

    if (abs(x2 - x3) < dist_x)
        dist_x = abs(x2 - x3);
    if (abs(x1 - x4) < dist_x)
        dist_x = abs(x1 - x4);
    if (abs(y2 - y3) < dist_y)
        dist_y = abs(y2 - y3);
    if (abs(y1 - y4) < dist_y)
        dist_y = abs(y1 - y4);

    return dist_x + dist_y;
}

vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
    vector<int> dists(g.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dists[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (t > dists[u]) continue;
        for (auto& [w, v] : g[u])
            if (t + w < dists[v]) {
                dists[v] = t + w;
                pq.emplace(t + w, v);
            }
    }
    return dists;
}

signed main() {
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;

    int n;
    cin >> n;

    vector<Quadrado> qs(n);
    for (auto& P : qs)
        cin >> x1 >> y1 >> x2 >> y2;

    qs.emplace_back(pair<int, int>(xi, yi), pair<int, int>(xi, yi));
    qs.emplace_back(pair<int, int>(xf, yf), pair<int, int>(xf, yf));

    vector<vector<pair<int, int>>> g(qs.size());
    for (int i = 0; i < qs.size(); ++i)
        for (int j = 0; j < qs.size(); ++j)
            g[i].emplace_back(distanciaQuadrados(qs[i], qs[j]), j);

    auto dists = dijkstra(g, g.size() - 2);
    cout << dists[g.size() - 1] << '\n';
}
