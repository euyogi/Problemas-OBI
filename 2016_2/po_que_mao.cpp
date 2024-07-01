// 2016 Fase 2: Po que mão (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/pokemon/)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> xs(3);
    for (int& x : xs) cin >> x;

    sort(all(xs));

    int i = 0;
    for (; i < 3; ++i) {
        if (xs[i] <= n)
            n -= xs[i];
        else
            break;
    }

    cout << i << '\n';
}
