// 2021 Fase 3: Festa olímpica (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f3/festa/)

#include <bits/stdc++.h>
using namespace std;

// padrão difícil de perceber veja comentário noic

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> ms(m);
    for (int& x : ms) cin >> x;

    vector<int> pos(1e4 + 1);
    iota(pos.begin(), pos.end(), 0);

    // basicamente vai retrocedendo e calculando o índice
    // que as posições vão virar após retroceder
    for (int i = m - 1; i >= 0; --i)
        for (int j = 1; j <= 1e4; ++j)
            if (pos[j] <= n)
                pos[j] += (pos[j] - 1) / (ms[i] - 1);

    for (int i = 1; i <= 1e4; ++i)
        if (pos[i] <= n) cout << pos[i] << '\n';
}
