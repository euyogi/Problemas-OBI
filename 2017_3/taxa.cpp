// 2017 Fase 3: Taxa (https://olimpiada.ic.unicamp.br/pratique/p2/2017/f3/taxa/)

#include <bits/stdc++.h>
using namespace std;

#define int long long
// cíclico
#define M(x) ((x + n) % (n))

int n;
vector<int> xs;
vector<vector<int>> dpsum, dpmin;

// soma de l até r (cíclica)
int sum(int l, int r) {
    l = M(l), r = M(r);
    if (l == r)
        dpsum[l][r] = xs[l];
    if (dpsum[l][r])
        return dpsum[l][r];
    return dpsum[l][r] = sum(l, r - 1) + xs[r];
}

// custo mínimo para cortar as regiões
// desejadas de l até r (cíclico)
int minimum(int l, int r) {
    l = M(l), r = M(r);
    if (l == r)
        dpmin[l][r] = 0;
    if (dpmin[l][r] != INT_MAX)
        return dpmin[l][r];

    for (int i = l; i != r; i = M(i + 1)) {
        int custo_corte = max(sum(l, i), sum(i + 1, r));
        dpmin[l][r] = min(dpmin[l][r], minimum(l, i) + minimum(i + 1, r) + custo_corte);
    }
    return dpmin[l][r];
}

signed main() {
    long double f;
    cin >> n >> f;

    xs.resize(n);
    dpsum.resize(n, vector<int>(n));
    dpmin.resize(n, vector<int>(n, INT_MAX));
    for (int& x : xs)
        cin >> x;

    int ans = minimum(0, n - 1);
    for (int i = 1; i < n; ++i)
        ans = min(ans, minimum(i, n - 1 + i));
    printf("%.2Lf\n", f * ans);
}
