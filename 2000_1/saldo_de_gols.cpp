// 2000 Fase única: Saldo de Gols (https://neps.academy/br/exercise/650)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, t = 1;
    while (cin >> n, n != 0) {
        vector<int> xs(n);
        for (int& x : xs) {
            int a, b;
            cin >> a >> b;
            x = a - b;
        }

        vector<int> psum(n + 1);
        for (int i = 0; i < n; ++i) psum[i + 1] = psum[i] + xs[i];

        int menor = INT_MAX, menor_idx;
        int maior_diff = -1, def_maior, def_menor;
        int ans = 0, maior_idx;
        for (int i = 1; i <= n; ++i) {
            if (psum[i - 1] < menor) {
                menor = psum[i - 1];
                menor_idx = i;
            }
            if (psum[i] - menor >= ans) {
                maior_idx = i;
                if ((psum[i] - menor > ans) or
                    (maior_idx - menor_idx >= maior_diff)) {
                    maior_diff = maior_idx - menor_idx;
                    def_maior = maior_idx;
                    def_menor = menor_idx;
                }
                ans = psum[i] - menor;
            }
        }

        cout << "Teste " << t << '\n';
        if (ans != 0)
            cout << def_menor << ' ' << def_maior << "\n\n";
        else
            cout << "nenhum\n\n";
        ++t;
    }
}
