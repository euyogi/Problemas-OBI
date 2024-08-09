// 2023 Fase 2: Prefixo (https://neps.academy/br/exercise/2437)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m;
    string p, s;
    cin >> n >> p >> m >> s;

    int ans = 0;
    for (; ans < min(n, m); ++ans)
        if (p[ans] != s[ans])
            break;
    cout << ans << '\n';
}
