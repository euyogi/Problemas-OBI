// 2023 Fase 2: Intervalo Distinto (https://neps.academy/br/exercise/2438)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;

    unordered_map<int, int> pos;

    int ans = 1, tam = 1;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        if (pos[x] >= i - tam)
            tam = i - pos[x];
        else
            ++tam;

        pos[x] = i;
        ans = max(ans, tam);
    }
    cout << ans << '\n';
}
