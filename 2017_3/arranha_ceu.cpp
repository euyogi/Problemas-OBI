// 2017 Fase 3: Arranha Céu (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/arranhaceu/)

#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> bt;

    BIT(int n) : bt(n + 1) {}

    void add(int i, int x) {
        for (; i < bt.size(); i += i & -i) bt[i] += x;
    }

    int rsq(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += bt[i];
        return sum;
    }
};

struct SegTree {
    vector<int> seg;
    int n;

    SegTree(int n) {
        while (__builtin_popcount(n) != 1) ++n;
        (*this).n = n;
        seg.resize(2 * n, 0);
    }

    int setQuery(int i, int j, int x = INT_MIN, int l = 0, int r = 0, int node = 0) {
        if (!node) {
            r = n - 1;
            node = 1;
        }
        if (i <= l and j >= r) {
            if (x != INT_MIN) seg[node] = x;
            return seg[node];
        }
        if (j < l or i > r) return 0;
        int m = l + (r - l) / 2;
        int sum = setQuery(i, j, x, l, m, 2 * node) + setQuery(i, j, x, m + 1, r, 2 * node + 1);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
        return sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    BIT bt(n);
    // SegTree seg(n);

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        bt.add(i + 1, x);
        // seg.setQuery(i, i, x);
    }

    while (q--) {
        int o, k, p;
        cin >> o >> k;

        if (o == 1) cout << bt.rsq(k) << '\n';
        // cout << seg.setQuery(0, k - 1) << '\n';
        else {
            cin >> p;
            int x = bt.rsq(k) - bt.rsq(k - 1);
            bt.add(k, p - x);
            // seg.setQuery(k - 1, k - 1, p);
        }
    }
}
