// 2018 Fase 2: Sequência (https://olimpiada.ic.unicamp.br/pratique/ps/2018/f2/sequencia/)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

signed main() {
    ll n, l, h;
    cin >> n >> l >> h;

    vll xs(n), marcado(n);

    for (ll& i : xs) cin >> i;
    for (ll& i : marcado) cin >> i;

    // dp[i][j]:
    // melhor soma do intervalo incluindo
    // elemento i com j números marcados, ou 0
    vvll dp(n, vll(h + 1, -INT_MAX));

    // caso base
    if (marcado[0]) {
        dp[0][0] = 0; // ñ pegar
        dp[0][1] = xs[0]; // pegar
    }
    else
        dp[0][0] = max(0LL, xs[0]);

    for (ll i = 1; i < n; ++i)
        for (ll j = 0; j <= h; ++j) {
            if (marcado[i]) {
                if (j == 0)
                    dp[i][0] = 0;
                else
                    dp[i][j] = dp[i - 1][j - 1] + xs[i];
            }
            else {
                if (j == 0)
                    dp[i][0] = max(0LL, dp[i - 1][0] + xs[i]);
                else
                    dp[i][j] = dp[i - 1][j] + xs[i];
            }
        }

    ll ans = -INT_MAX;
    for (ll i = 0; i < n; ++i)
        for (ll j = l; j <= h; ++j)
            ans = max(dp[i][j], ans);
    cout << ans << '\n';
}
