// 2018 Fase 3: Baldes (https://olimpiada.ic.unicamp.br/pratique/p2/2018/f3/baldes/)

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    vector<T> seg;
    const T DEF = {INT_MIN, INT_MIN};
    int n;

    SegTree(int n) {
        while (__builtin_popcount(n) != 1) ++n;
        (*this).n = n;
        seg.resize(2 * n, DEF);
    }

    T setQuery(int i, int j, T x = { INT_MIN, INT_MIN }, int l = 0, int r = -1, int node = 1) {
        if (r == -1) r = n - 1;
        if (i <= l and r <= j) {
            if (x != pair<int, int>({ INT_MIN, INT_MIN })) seg[node] = x;
            return seg[node];
        }
        if (r < i or l > j) return DEF;
        int m = (l + r) / 2;
        T maximum = max(setQuery(i, j, x, l, m, 2 * node), setQuery(i, j, x, m + 1, r, 2 * node + 1));
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
        return maximum;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, op;
    cin >> n >> m;

    // segmax guardando os índices porque o máximo e mínimo
    // tem que estar em índices diferentes
    SegTree<pair<int, int>> maiores(n);
    SegTree<pair<int, int>> menores(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        maiores.setQuery(i, i, {x, i});
        // vou simular uma segmin pondo os valores negativos
        menores.setQuery(i, i, {-x, i});
    }

    while (m--) {
        cin >> op;

        if (op == 1) {
            pair<int, int> pi;
            cin >> pi.first >> pi.second;
            --pi.second;
            int i = pi.second;
            pair<int, int> pim = { -pi.first, pi.second };
            if (pi > maiores.setQuery(i, i))
                maiores.setQuery(i, i, pi);
            // e.g. 5 < 10, mas como estão negativos, -5 > -10
            if (pim > menores.setQuery(i, i))
                menores.setQuery(i, i, pim);
        }
        else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            pair<int, int> c1 = maiores.setQuery(a, b);
            pair<int, int> c2 = menores.setQuery(a, max(0, c1.second - 1));
            pair<int, int> c3 = menores.setQuery(min(n - 1, c1.second + 1), b);
            if (c3.first > c2.first) c2 = c3;
            int res = c1.first + c2.first;

            // pode ser que seja melhor pegar o mínimo do balde
            // com o máximo e pegar o máximo dos outros
            c1 = menores.setQuery(a, b);
            c2 = maiores.setQuery(a, max(0, c1.second - 1));
            c3 = maiores.setQuery(min(n - 1, c1.second + 1), b);
            if (c3.first > c2.first) c2 = c3;
            res = max(res, c2.first + c1.first);

            cout << res << '\n';
        }
    }
}
