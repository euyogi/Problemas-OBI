// 2017 Fase 2: Cortando o Papel (https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/papel/)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> hs;
    hs.emplace_back(0);
    for (int i = 0, h; i < n; ++i) {
        cin >> h;
        if (h != hs.back()) hs.emplace_back(h);
    }
    hs.emplace_back(0);

    vector<int> vales, picos;
    int ant, at, prox;

    for (int i = 1; i < hs.size() - 1; ++i) {
        ant = hs[i - 1], at = hs[i], prox = hs[i + 1] ;

        if (ant < at and at > prox)
            picos.emplace_back(at);
        else if (ant > at and at < prox)
            vales.emplace_back(at);
    }

    vector<int> aux(all(vales));
    aux.insert(aux.end(), all(picos));

    sort(all(vales));
    sort(all(picos));

    int ans = 2;
    for (int h : aux) {
        int potencial = 2 + (upper_bound(all(vales), h) - vales.begin()) - (upper_bound(all(picos), h) - picos.begin());
        ans = max(ans, potencial);
    }
    cout << ans << '\n';
}