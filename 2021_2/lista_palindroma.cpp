// 2021 Fase 2: Lista Palíndroma (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/lista/)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<int> xs(n);
    for (int& x : xs) cin >> x;

    int i = 0, j = n - 1, ans = 0;
    while (i < j) {
        ++ans;
        if (xs[i] == xs[j])
            ++i, --j, --ans;
        else if (xs[i] < xs[j]) {
            ++i;
            xs[i] += xs[i - 1];
        }
        else {
            --j;
            xs[j] += xs[j + 1];
        }
    }

    cout << ans << '\n';
}
