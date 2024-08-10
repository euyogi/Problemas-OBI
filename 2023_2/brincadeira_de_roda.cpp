// 2023 Fase 2: Brincadeira de Roda (https://neps.academy/br/exercise/2621)

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, i, p;
    cin >> n >> i >> p;
    cout << (i + p - 1) % (n) + 1 << '\n';
}
