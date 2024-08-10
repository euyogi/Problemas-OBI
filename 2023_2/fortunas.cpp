// 2023 Fase 2: Fortunas (https://neps.academy/br/exercise/2626)

// a ideia é a seguinte: as reuniões se espalham
// pra cima e pra baixo se o nó tiver no intervalo,
// então vamos guardar o intervalo da reunião no nó
// mais alto que participa dela em vez da anfitriã.
// assim, podemos fazer uma dfs que checa se o nó
// é anfitrião, marca o intervalo como reunião e desce
// fazendo o mesmo, na hora de subir a gente marca
// quantas reuniões esse nó participou e tira as
// os intervalos das reuniões que esse nó anfitriou

// para marcar o novo anfitrião usamos binary lifting
// e ideia do LCA.
// para marcar os intervalos usamos uma segment tree

#include <bits/stdc++.h>
using namespace std;

const int LOG = 32;
vector<vector<int>> parent, g;
vector<int> value;

void populate(int n) {
    value.resize(n + 1);
    parent.resize(n + 1, vector<int>(LOG));
    g.resize(n + 1);

    // relações conhecidas
    for (int i = 1, a, b; i <= n; ++i) {
        cin >> a >> b;
        value[i] = a;
        parent[i][0] = b;
        if (i > 1)
            g[b].emplace_back(i);
    }

    for (int i = 1; i < LOG; ++i)
        for (int j = 1; j <= n; ++j)
            parent[j][i] = parent[ parent[j][i - 1] ][i - 1];
}

// mesma ideia do LCA
int LCA(int u, int r) {
    for (int i = LOG - 1; i >= 0; --i)
        if (value[parent[u][i]] <= r)
            u = parent[u][i];
    return u;
}

struct SegTree {
    vector<int> seg;
    int n;

    SegTree(int n) {
        while (__builtin_popcount(n) != 1) ++n;
        (*this).n = n;
        seg.resize(2 * n);
    }

    int setQuery(int i, int j, int x = INT_MAX, int l = 0, int r = -1, int node = 1) {
        if (r == -1) r = n - 1;
        if (i <= l and r <= j) {
            if (x != INT_MAX) seg[node] += x;
            return seg[node];
        }
        if (r < i or l > j) return 0;
        int m = (l + r) / 2;
        int sum = setQuery(i, j, x, l, m, 2 * node) + setQuery(i, j, x, m + 1, r, 2 * node + 1);
        return sum + seg[node];
    }
};

signed main() {
    int n, m;
    cin >> n >> m;

    populate(n);

    vector<vector<pair<int, int>>> reunioes(n + 1);
    for (int i = 0, u, l, r; i < m; ++i) {
        cin >> u >> l >> r;
        int v = LCA(u, r);
        reunioes[v].emplace_back(l, r);
    }

    SegTree seg(1e5 + 10);
    vector<int> ans(n + 1);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        for (auto [l, r] : reunioes[u])
            seg.setQuery(l, r, 1);

        for (int v : g[u]) if (v != p)
            self(self, v, u);

        ans[u] = seg.setQuery(value[u], value[u]);

        for (auto [l, r] : reunioes[u])
            seg.setQuery(l, r, -1);
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << (i == n ? '\n' : ' ');
}
