// 2020 Fase 2: Caixeiro Viajante (https://olimpiada.ic.unicamp.br/pratique/ps/2020/f2/caixeiro/)

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

signed main() {
    int n;
    cin >> n;

    vvi tempo(1510, vi(1510)), dp(1510, vi(1510, INT_MAX));
    for (int i = 0, u, v; i < n * (n - 1) / 2; ++i) {
        cin >> u >> v;
        cin >> tempo[u][v];
        tempo[v][u] = tempo[u][v];
    }

    // considerando que viagens sejam definidas
    // apenas pelo seu tempo, viagens que passam
    // por todas as cidades sempre terminarão na
    // cidade n. aquelas que comecariam em n são
    // iguais às inversas que terminam em n

    // estados da dp: [última cidade][primeira cidade]
    // por conveniência vou sempre utilizar i >= j.
    // dp[i][j] é o menor tempo para chegar em i de j,
    // passando por todas as cidades menores que i ou
    // vice-versa

    dp[2][1] = tempo[1][2];
    for (int i = 3; i <= n; ++i)
        for (int j = 1; j < i - 1; j++) {
            // i -> j -> ..1.. -> i - 1
            dp[i][i - 1] = min(dp[i][i - 1], tempo[i][j] + dp[i - 1][j]);
            // j -> ..1.. -> i - 1 -> i
            dp[i][j] = dp[i - 1][j] + tempo[i - 1][i];
        }

    cout << *min_element(dp[n].begin() + 1, dp[n].begin() + n) << '\n';
}
