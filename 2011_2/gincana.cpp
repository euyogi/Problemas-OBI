// 2011 Fase 2: Gincana (https://neps.academy/br/exercise/309)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1) { iota(all(parent), 0); }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void merge(int x, int y) {
        int a = find(x), b = find(y);
        if (size[b] > size[a]) swap(a, b);
        parent[b] = a;
        if (a != b) {
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

signed main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dsu.size[i] != 0) ++ans;
    cout << ans << '\n';
}
