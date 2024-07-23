// 2020 Fase 2: Estrada (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f2/estrada/)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
    int t, n;
    cin >> t >> n;

    vector<long double> cs(n);
    for (long double& c : cs) cin >> c;

    sort(all(cs));

    long double menor = t;
    for (int i = 0; i < cs.size(); ++i) {
        if (i == 0)
            menor = cs[i] + (cs[i + 1] - cs[i]) / 2.0f;
        else if (i == cs.size() - 1)
            menor = min(menor, (cs[i] - cs[i - 1]) / 2.0f + t - cs[i]);
        else
            menor = min(menor, (cs[i] - cs[i - 1]) / 2.0 + (cs[i + 1] - cs[i]) / 2.0);
    }

    printf("%.2Lf\n", menor);
}
