// 2021 Fase 2: Mínimo e máximo (https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/minmax/)

#include <bits/stdc++.h>
using namespace std;

int somaDigitos(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main() {
    int s, a, b, menor, maior;
    cin >> s >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (somaDigitos(i) == s) {
            menor = min(menor, i);
            maior = max(maior, i);
        }
    }

    cout << menor << '\n' << maior << '\n';
}
