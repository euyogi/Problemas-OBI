// 2022 Fase 3: Quadrado (https://neps.academy/br/exercise/2174)

#include <bits/stdc++.h>
using namespace std;

// se é ímpar basta printar de 1 até n^2
// se é par eu vi que o último em vez de
// ser + 1 é + n / 2 + 1, o primeiro da última
// linha vai ser a o da linha anterior + a
// diferença entre o primeiro da linha anterior
// e da linha anterior a anterior vezes n / 2 + 1
// eu chequei até n = 40 e funcionou

signed main() {
    int n, c = 1;
    cin >> n;

    vector matriz(n, vector<int>(n));

    if (n & 1)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cout << (c++) << (j == n - 1 ? '\n' : ' ');
                // matriz[i][j] = c++;
            }
    else {
        if (n == 2) {
            cout << -1 << '\n';
            return 0;
        }

        int anterior = 1;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) c = anterior + (c - anterior) * (n / 2 + 1);
            anterior = c;
            for (int j = 0; j < n; ++j)
                if (j == n - 1) {
                    cout << (c = (c - 1) + (n / 2 + 1)) << '\n';
                    // matriz[i][j] = (c = (c - 1) + (n / 2 + 1));
                    ++c;
                }
                else {
                    cout << (c++) << ' ';
                    // matriz[i][j] = c++;
                }
        }
    }
}
