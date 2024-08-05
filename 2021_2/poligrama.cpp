// 2021 Fase 2: Poligrama (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/poligrama/)

#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int x) {
    vector<int> ds{1};
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            ds.emplace_back(i);
            if (i * i != x) ds.emplace_back(x / i);
        }
    return ds;
}

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto ds = divisors(n);
    sort(ds.begin(), ds.end());

    // p/ checar frequência de cada caractere em intervalo
    vector<vector<int>> psums(26, vector<int>(s.size() + 1));
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < s.size(); ++j)
            psums[i][j + 1] = psums[i][j] + (s[j] - 'a' == i);

    // checar se uma raiz de tamanho d é possível
    for (int d : ds) {
        vector<int> freq_raiz(26);
        for (int i = 0; i < 26; ++i)
            freq_raiz[i] = psums[i][d];

        bool raiz = true;

        for (int i = d; i <= s.size(); i += d) {
            vector<int> freq_sub(26);
            for (int j = 0; j < 26; ++j)
                freq_sub[j] = psums[j][i] - psums[j][i - d];

            if (freq_raiz != freq_sub) {
                raiz = false;
                break;
            }
        }

        if (raiz) {
            cout << s.substr(0, d) << '\n';
            return 0;
        }
    }

    cout << "*\n";
}
