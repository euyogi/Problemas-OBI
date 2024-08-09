// 2023 Fase 2: Barcos da Nlogônia (https://neps.academy/br/exercise/2439)

#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using ti = tuple<int, int, int>;
using vti = vector<ti>;

struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    void merge(int x, int y) {
        int a = find(x), b = find(y);
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = p[a];
        if (a != b)
            sz[a] += sz[b];
    }
};

vti kruskal(vti& edges, int n) {
    vti mst;
    DSU dsu(n);
    sort(edges.begin(), edges.end(), greater<>());
    for (auto [w, u, v] : edges)
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            mst.emplace_back(w, u, v);
        }
    return mst;
}

const int LOG = 31;
vector<vector<int>> parent;
// menor_aresta[i][j]: menor aresta no caminho de
// i para seu 2^j parente
vector<vector<int>> menor_aresta;
vector<int> depth;

void populate(vti& edges, int n) {
    parent.resize(n + 1, vector<int>(LOG));
    menor_aresta.resize(n + 1, vector<int>(LOG, INT_MAX));
    depth.resize(n + 1);

    // relações conhecidas
    vvpi g(n + 1);
    for (auto [w, u, v] : edges) {
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }

    auto dfs = [&](auto&& self, int u, int p) -> void {
        parent[u][0] = p;
        depth[u] = depth[p] + 1;
        for (auto [w, v] : g[u])
            if (v != p) {
                // de v para seu pai a menor aresta
                // vai ser a única: w
                menor_aresta[v][0] = w;
                self(self, v, u);
            }
    };
    dfs(dfs, 1, 0);
    parent[1][0] = 1;

    for (int i = 1; i < LOG; ++i)
        for (int j = 1; j <= n; ++j) {
            // segue a mesma lógica do binary lifting
            menor_aresta[j][i] = min(menor_aresta[j][i - 1], menor_aresta[parent[j][i - 1]][i - 1]);
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
}

pi kthAncestor(int u, int k) {
    // menor aresta no trajeto de u para seu k-ancestral
    int menor = INT_MAX;
    for (int i = 0; i < LOG; ++i)
        if (k & 1 << i) {
            menor = min(menor, menor_aresta[u][i]);
            u = parent[u][i];
        }
    return { u, menor };
}

// modificado para retornar a menor aresta entre a
// do trajeto de u para lca e a de v para lca
int LCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    // menor aresta no trajeto de u para seu k-ancestral
    int ans = INT_MAX;
    if (k > 0) {
        auto [kth, menor] = kthAncestor(u, k);
        ans = menor;
        u = kth;
    }
    if (u == v)
        return ans;
    for (int i = LOG - 1; i >= 0; --i)
        if (parent[u][i] != parent[v][i]) {
            ans = min(ans, menor_aresta[u][i]);
            ans = min(ans, menor_aresta[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    return min({ans, menor_aresta[u][0], menor_aresta[v][0]});
}

signed main() {
    int n, b, c;
    cin >> n >> b;

    vti edges(b);
    for (auto& [w, u, v] : edges)
        cin >> u >> v >> w;

    // vou fazer tipo um lca mas em vez de
    // retornar um vértice eu vou retornar
    // a menor aresta até o lca
    auto mst = kruskal(edges, n);
    populate(mst, n);

    cin >> c;

    while (c--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
}
