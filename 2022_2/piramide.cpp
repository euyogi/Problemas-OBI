// 2022 Fase 2: Pirâmide (https://neps.academy/br/exercise/2128)

#include <bits/stdc++.h>
using namespace std;

int distanciaBorda(int i, int j, int n) {
    return min(min(i, j), min(n - i - 1, n - j - 1));
}

signed main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << distanciaBorda(i, j, n) + 1 << (j == n - 1 ? '\n' : ' ');
}
