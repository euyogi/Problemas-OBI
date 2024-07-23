// 2019 Fase 2: Matriz super-legal (https://olimpiada.ic.unicamp.br/pratique/pu/2019/f2/matriz/)
// 80/100 Pontos

#include <bits/stdc++.h>
using namespace std;

int maiorRetEmHistograma(const vector<int>& hist) {
    // first: índice do menor elemento à esquerda + 1
    // second: índice do menor elemento à direita
    vector<pair<int, int>> idx_menores(hist.size(), {-1, hist.size()});
    stack<int> anteriores;

    for (int i = 0; i < hist.size(); ++i) {
        while (!anteriores.empty() and hist[anteriores.top()] >= hist[i])
            anteriores.pop();
        if (!anteriores.empty())
            idx_menores[i].first = anteriores.top();
        anteriores.emplace(i);
    }

    anteriores = stack<int>();

    for (int i = hist.size() - 1; i >= 0; --i) {
        while (!anteriores.empty() and hist[anteriores.top()] >= hist[i])
            anteriores.pop();
        if (!anteriores.empty())
            idx_menores[i].second = anteriores.top();
        anteriores.emplace(i);
    }

    int ans = 0;
    for (int i = 0; i < hist.size(); ++i) {
        int base = idx_menores[i].second - (idx_menores[i].first);
        ans = max(ans, hist[i] * base);
    }
    return ans;
}

signed main() {
    int l, c;
    cin >> l >> c;

    vector<vector<int>> a(l, vector<int>(c)), b = a;
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    // marca matrizes legais 2x2
    for (int i = 0; i < l - 1; ++i)
        for (int j = 0; j < c - 1; ++j)
            if (a[i][j] + a[i + 1][j + 1] <= a[i][j + 1] + a[i + 1][j])
                b[i][j] = true;

    // altura de cada coluna
    for (int i = l - 1; i >= 0; --i)
        for (int j = c - 1; j >= 0; --j) {
            a[i][j] = 2 * b[i][j];
            if (b[i][j] and i < l - 1)
                a[i][j] += max(0, a[i + 1][j] - 1);
        }

    int ans = 0;
    for (auto& hist : a)
        ans = max(ans, maiorRetEmHistograma(hist));
    cout << ans << '\n';
}
