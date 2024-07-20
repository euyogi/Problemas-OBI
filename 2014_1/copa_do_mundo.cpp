// 2014 Fase 1: Copa do Mundo (https://olimpiada.ic.unicamp.br/pratique/p2/2014/f1/copa/)

#include <bits/stdc++.h>
using namespace std;
#define all(xs) xs.begin(), xs.end()

class DSU {
   public:
    DSU(size_t n) : parent(n + 1), size(n + 1, 1) { iota(all(parent), 0); }

    int setOf(int x) { return parent[x] == x ? x : parent[x] = setOf(parent[x]); }

    void mergeSetsOf(int x, int y) {
        int a = setOf(x), b = setOf(y);
        if (size[a] > size[b]) swap(a, b);
        parent[a] = b;
        if (a != b) size[b] += size[a];
    }

    bool sameSet(int x, int y) { return setOf(x) == setOf(y); }

   private:
    vector<int> parent, size;
};

pair<vector<tuple<int, int, int>>, int>
kruskal(vector<tuple<int, int, int>>& ferrovias, vector<tuple<int, int, int>>& rodovias, int n) {
    DSU dsu(n);
    vector<tuple<int, int, int>> mst;
    int edges_sum = 0;
    sort(all(ferrovias));
    sort(all(rodovias));
    for (auto [w, u, v] : ferrovias)
        if (!dsu.sameSet(u, v)) {
            mst.emplace_back(w, u, v);
            dsu.mergeSetsOf(u, v);
            edges_sum += w;
        }
    for (auto [w, u, v] : rodovias)
        if (!dsu.sameSet(u, v)) {
            mst.emplace_back(w, u, v);
            dsu.mergeSetsOf(u, v);
            edges_sum += w;
        }
    return {mst, edges_sum};
}

signed main() {
    int n, f, r;
    cin >> n >> f >> r;

    vector<tuple<int, int, int>> ferrovias(f), rodovias(r);
    for (auto& [w, u, v] : ferrovias) cin >> u >> v >> w;
    for (auto& [w, u, v] : rodovias) cin >> u >> v >> w;
    auto [mst, sum] = kruskal(ferrovias, rodovias, n);
    cout << sum << '\n';
}
