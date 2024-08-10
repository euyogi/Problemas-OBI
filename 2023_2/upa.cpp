// 2023 Fase 2: UPA (https://neps.academy/br/exercise/2622)

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    vector<int> seg;
    const int DEF = 0;
    int n;

    SegTree(int n) {
        while (__builtin_popcount(n) != 1)
            ++n;
        (*this).n = n;
        seg.resize(2 * n, DEF);
    }

    int setQuery(int i, int j, int x = INT_MIN, int l = 0, int r = -1, int node = 1) {
        if (r == -1) r = n - 1;
        if (i <= l and j >= r) {
            if (x != INT_MIN)
                seg[node] += x;
            return seg[node];
        }
        if (r < i or l > j) return DEF;
        int m = (l + r) / 2;
        int sum = setQuery(i, j, x, l, m, 2 * node) + setQuery(i, j, x, m + 1, r, 2 * node + 1);
        return sum + seg[node];
    }
};

signed main() {
    int n;
    cin >> n;

    SegTree seg(1e5 + 10);

    while (n--) {
        int l, r;
        cin >> l >> r;
        seg.setQuery(l, r - 1, 1);
    }

    int ans = 0;
    for (int i = 0; i <= 1e5; ++i)
        ans = max(ans, seg.setQuery(i, i));
    cout << ans * 20 << '\n';
}
