// 2007 Fase 2: Pizza (https://olimpiada.ic.unicamp.br/pratique/p2/2007/f2/pizza/)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> xs(n);
    for (int& x : xs) cin >> x;

    vector<int> psum(n + 1);
    for (int i = 0; i < n; ++i) psum[i + 1] = psum[i] + xs[i];

    int menor = INT_MAX, ans = 0;
    for (int i = 1; i <= n; ++i) {
        menor = min(menor, psum[i - 1]);
        ans = max(ans, psum[i] - menor);
    }

    int melhor_atravessando = 0, melhor_contendo_primeiro = 0;
    for (int i = 1; i <= n and n > 2; ++i) {
        melhor_contendo_primeiro = max(melhor_contendo_primeiro, psum[i]);
        melhor_atravessando =
            max(melhor_atravessando,
                psum.back() - psum[i] + melhor_contendo_primeiro);
    }

    cout << max(ans, melhor_atravessando) << '\n';
}
