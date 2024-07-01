// 2015 Fase 2: Catador (https://olimpiada.ic.unicamp.br/pratique/ps/2015/f2/catador/)

#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> bt;

    BIT(int n) : bt(n + 1) {}

    void add(int i, int x) {
        for (; i > 0; i -= i & -i)
            bt[i] += x;
    }

    int rsq(int i) {
        int sum = 0;
        for (; i < bt.size(); i += i & -i)
            sum += bt[i];
        return sum;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;

    BIT bt(n);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;

        bt.add(i, x);
        bt.add(i-1, -x);
    }

    for (int i = 0, j; i < m; ++i) {
        cin >> j;

        int range = max(bt.rsq(j), 0);

        bt.add(min(j + range, n), -1);
        bt.add(max(j - range - 1, 0), 1);
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += max(bt.rsq(i), 0);

    cout << sum << '\n';
}
