// 2021 Fase 2: Senha da Vó Zinha (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/senha/)

#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

vector<int> coeficientes(int x, int base) {
    vector<int> cs;
    while (x) {
        cs.emplace_back(x % base);
        x /= base;
    }
    reverse(all(cs));
    return cs;
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<int> apagadas(m);
    for (int i = 0, c = 0; i < n; ++i)
        if (s[i] == '#') apagadas[c++] = i;

    vector<string> ps(m);
    for (string& p : ps) {
        cin >> p;
        sort(all(p));
    }

    int p;
    cin >> p;

    auto cs = coeficientes(p - 1, k);

    while (cs.size() < m)
        cs.emplace(cs.begin(), 0);

    for (int i = 0; i < cs.size(); ++i)
        s[apagadas[i]] = ps[i][cs[i]];
    cout << s << '\n';
}
